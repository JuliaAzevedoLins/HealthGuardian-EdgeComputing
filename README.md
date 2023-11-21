<h1 align="center">HealthGuardian! 🩺💊</h1>

###

<p align="center">Repositório dedicado ao nosso trabalho de Edge Computing da Global Solution 2023.2</p>

###

<div align="center">
  <p align="center">Clique aqui para o nosso vídeo explicativo no Youtube</p>
  <img src="https://img.shields.io/static/v1?message=Youtube&logo=youtube&label=&color=FF0000&logoColor=white&labelColor=&style=for-the-badge" height="40" alt="youtube logo"  />
</div>

###

<div align="center">
  <img height="200" src="https://i.pinimg.com/originals/70/37/d4/7037d478852af21357f038fac2d2e9f6.gif"  />
</div>

## Integrantes - ESPW
- Julia Azevedo Lins: RM98690
- Luís Gustavo Barreto Garrido: RM99210

## Descrição
O Health Guardian é um sistema de monitoramento de saúde que permite aos usuários responder a perguntas sobre seus sintomas e enviar as respostas para um servidor remoto. O sistema ajuda a avaliar a condição de saúde do usuário e fornece orientações com base nas respostas.

## Funcionalidades
- Exibe perguntas sobre sintomas em um display touchscreen.
- Coleta respostas dos usuários (Sim ou Não).
- Envia os dados para um servidor remoto para avaliação.

## Componentes
- Microcontrolador ESP32
- Display TFT Touchscreen (Adafruit ILI9341)
- Módulo Wi-Fi para conectividade à Internet

## Configuração do Hardware
1. Conecte o display TFT ao ESP32 conforme as definições nos pinos (TFT_DC e TFT_CS).
2. Conecte os botões físicos aos pinos BTN_PIN_01 e BTN_PIN_02.
3. Alimente o ESP32 e o display.

## Configuração do Software
1. Configure as credenciais Wi-Fi (SSID e senha) no código.
2. Certifique-se de ter as bibliotecas necessárias instaladas (WiFi, HTTPClient, Adafruit_GFX, Adafruit_ILI9341).
3. Carregue o código no ESP32.

## Uso
1. O sistema exibirá uma mensagem de boas-vindas no início.
2. Responda às perguntas sobre seus sintomas pressionando os botões "Sim" ou "Não".
3. As respostas serão enviadas para um servidor remoto.
4. Com base nas respostas, o sistema fornecerá orientações para os usuários.
