Projeto WitAI-TTS - Microcontroladores
Este projeto consiste na implementação de um sistema de Text-to-Speech (TTS) utilizando o microcontrolador ESP32 integrado à API Wit.ai da Meta. O objetivo é permitir que o hardware converta mensagens de texto em áudio natural em tempo real, utilizando o protocolo de comunicação digital I2S.

🚀 Sobre o Projeto
A aplicação utiliza a biblioteca WitAITTS para realizar requisições HTTPS à API do Wit.ai, processando o stream de áudio recebido e reproduzindo-o através de um periférico externo de áudio.

Principais funcionalidades:

Conversão de texto para voz com suporte a múltiplas vozes (masculinas e femininas).

Personalização de estilo de fala, tom (pitch) e velocidade.

Saída de áudio de alta fidelidade via protocolo I2S.

transferência de dados via MQTT, com integração com o frontend


🛠️ Hardware Utilizado
Microcontrolador: ESP32 (DevKit V1 / S3 / C3).
DAC/Amplificador: Módulo MAX98357A (Interface I2S).
Saída: Alto-falante de 4-8 Ohms (3W).

👥 Integrantes do Grupo
Esther
Beatriz
Ernandy
Gabriela
Bruno

Como rodar o projeto
Configure as credenciais de Wi-Fi e o WIT_TOKEN no código fonte, após isso faça o uploud a do seu INO nas esp32. (garanta que as devidas bibliotecas estejam configuradas).
Em anexo do repositório, iremos deixar a biblioteca que foi essencial para a configuração do ambiente.

Certifique-se de ter as dependências instaladas via PlatformIO.
Faça o upload para o ESP32 e abra o Serial Monitor para enviar os textos que serão falados.

Cadeira: Microcontroladores
Instituição: Unifavip Wyden
Ano: 2026
