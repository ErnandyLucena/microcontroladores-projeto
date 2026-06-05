# 🎙️ WitAI-TTS para ESP32

Projeto desenvolvido para a disciplina de **Microcontroladores** da **UNIFAVIP Wyden**, com o objetivo de implementar um sistema de **Text-to-Speech (TTS)** utilizando o microcontrolador **ESP32** integrado à API **Wit.ai**, da Meta.

O sistema é capaz de converter textos em fala natural em tempo real, reproduzindo o áudio através de dispositivos compatíveis com o protocolo **I2S**. Além disso, conta com integração via **MQTT**, permitindo a comunicação entre o hardware e uma aplicação frontend para envio e recebimento de dados.

---

## 🚀 Sobre o Projeto

A aplicação utiliza a biblioteca **WitAITTS** para realizar requisições HTTPS à API do Wit.ai, processar o fluxo de áudio recebido e reproduzi-lo por meio de um periférico de áudio externo conectado ao ESP32.

### ✨ Funcionalidades

- Conversão de texto para voz (*Text-to-Speech*);
- Suporte a múltiplas vozes (masculinas e femininas);
- Personalização de:
  - Estilo de fala;
  - Tom da voz (*pitch*);
  - Velocidade de reprodução;
- Reprodução de áudio com alta qualidade utilizando o protocolo I2S;
- Comunicação em tempo real através do protocolo MQTT;
- Integração com frontend para envio de mensagens e controle do sistema.

---

## 🛠️ Hardware Utilizado

| Componente | Descrição |
|------------|------------|
| Microcontrolador | ESP32 (DevKit V1, ESP32-S3 ou ESP32-C3) |
| DAC/Amplificador | MAX98357A (Interface I2S) |
| Saída de Áudio | Alto-falante de 4–8 Ω (3W) |

---

## ⚙️ Tecnologias Utilizadas

- ESP32
- C++
- Arduino Framework
- Wit.ai API
- MQTT
- Wi-Fi
- I2S
- PlatformIO

---

## 🚀 Como Executar o Projeto

### 1. Configurar Credenciais

Configure as credenciais de Wi-Fi e o token da API Wit.ai no código-fonte:

```cpp
const char* WIFI_SSID = "SEU_WIFI";
const char* WIFI_PASSWORD = "SUA_SENHA";
const char* WIT_TOKEN = "SEU_TOKEN";
```

### 2. Configurar as Dependências

Certifique-se de que todas as bibliotecas necessárias estejam instaladas e configuradas corretamente no ambiente de desenvolvimento.

Uma cópia da biblioteca utilizada no projeto será disponibilizada junto ao repositório para facilitar a configuração do ambiente.

### 3. Compilar e Fazer Upload

Utilizando o PlatformIO:

```bash
pio run
pio run --target upload
```

Ou faça o upload diretamente pela Arduino IDE, caso o projeto esteja configurado para esse ambiente.

### 4. Executar

Após a gravação do firmware:

1. Conecte a ESP32 à rede Wi-Fi configurada;
2. Abra o Serial Monitor para acompanhar os logs do sistema;
3. Envie textos pelo frontend ou via MQTT;
4. O dispositivo realizará a conversão do texto em fala e reproduzirá o áudio pelo alto-falante conectado.

---

## 👥 Equipe do Projeto

- [Ernandy Lucena](https://github.com/ErnandyLucena)
- [Bruno José](https://github.com/BrunoJose18)
- [Esther Vila Nova](https://github.com/evncosta)
- [Beatriz Vila Nova](https://github.com/beatrizvnn)
- [Gabriela Silva](https://github.com/gabiissilvaa)

---

## 🎓 Informações Acadêmicas

**Disciplina:** Microcontroladores  
**Instituição:** UNIFAVIP Wyden  
**Ano:** 2026

---

## 📌 Observações

Este projeto possui fins acadêmicos e foi desenvolvido para demonstrar a integração entre sistemas embarcados, serviços de inteligência artificial, protocolos IoT e reprodução de áudio digital em tempo real.
