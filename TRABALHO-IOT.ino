#include <WitAITTS.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "WIFI";
const char* password = "SENHA";
const char* witToken = "token"; 

// Configurações da Nuvem MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "projeto/voz/1984729"; 

const char* mqtt_topic_historico = "projeto/voz/1984729/historico";

WiFiClient espClient;
PubSubClient client(espClient);
WitAITTS tts;

String historico[5]; 

void callback(char* topic, byte* payload, unsigned int length) {
    String textoRecebido = "";
    for (int i = 0; i < length; i++) {
        textoRecebido += (char)payload[i];
    }
    
    if (textoRecebido == "CMD:GET_HISTORY") {
        Serial.println("Frontend solicitou o historico.");
        
        String payloadHistorico = "";
        for(int i = 0; i < 5; i++) {
            if (historico[i] != "") {
                payloadHistorico += historico[i] + "|";
            }
        }
        
        client.publish(mqtt_topic_historico, payloadHistorico.c_str());
        return; 
    }
    
    Serial.print("Chegou da nuvem: ");
    Serial.println(textoRecebido);
    
    for(int i = 4; i > 0; i--) {
        historico[i] = historico[i-1];
    }

    historico[0] = textoRecebido;
    
    tts.speak(textoRecebido);
}

void reconectarMQTT() {
    while (!client.connected()) {
        Serial.print("Conectando ao Broker MQTT..");
        String clientId = "ESP32Client-";
        clientId += String(random(0, 1000));
        
        if (client.connect(clientId.c_str())) {
            Serial.println("Conectado");
          
            client.subscribe(mqtt_topic);
        } else {
            Serial.print("Falhou, rc=");
            Serial.print(client.state());
            Serial.println(" Tentando de novo em 5s...");
            delay(5000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("\n--- Iniciando Cliente MQTT IoT com Historico ---");
    
    for(int i=0; i<5; i++) {
        historico[i] = "";
    }
    
    if (tts.begin(ssid, password, witToken)) {
        Serial.println("API de Voz Pronta.");
    }
    
    tts.setGain(0.1); 
    tts.setSpeed(80);
    
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback); 
}

void loop() {

    tts.loop();
    
    if (!client.connected()) {
        reconectarMQTT();
    }
    client.loop();
}