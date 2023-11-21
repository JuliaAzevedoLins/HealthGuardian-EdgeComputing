<h1 align="center">HealthGuardian! 🩺💊</h1>

###

<p align="center">Repositório dedicado ao nosso trabalho de Edge Computing da Global Solution 2023.2</p>

###

<div align="center">
  <p align="center">Clique aqui para o nosso vídeo explicativo no <a href="https://www.youtube.com/">Youtube</a></p>
  <a href="https://www.youtube.com/">
    <img src="https://img.shields.io/static/v1?message=Youtube&logo=youtube&label=&color=FF0000&logoColor=white&labelColor=&style=for-the-badge" height="40" alt="youtube logo"  />
  </a>
</div>

###

<div align="center">
  <img height="200" src="https://i.pinimg.com/originals/70/37/d4/7037d478852af21357f038fac2d2e9f6.gif"  />
</div>

## Integrantes - ESPW
- Julia Azevedo Lins: RM98690
- Luís Gustavo Barreto Garrido: RM99210

## Simulação no Wokwi
Acesse nossa simulação no Wokwi para visualizar o projeto em ação: 
[https://wokwi.com/projects/381970792120545281](https://wokwi.com/projects/381970792120545281)

![Imagem do HealthGuardian no Wokwi](https://raw.githubusercontent.com/JuliaAzevedoLins/HealthGuardian-EdgeComputing/main/HealthGuardian%20-%20Imagem%20no%20Wokwi.png)

## Descrição
O Health Guardian é um sistema de monitoramento pós-hospitalar, que permite aos usuários responder a perguntas sobre seus sintomas e enviar as respostas para um servidor remoto. O sistema ajuda a avaliar a condição de saúde do usuário e fornece orientações com base nas respostas, determinando se há necessidade de retorno ao hospital.

## Funcionalidades
- Exibe perguntas sobre sintomas em um display.
- Coleta respostas dos usuários por meio dos botões (Sim ou Não).
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

## Integração com o Firebase (Banco de dados)

O Health Guardian utiliza o Firebase como plataforma de armazenamento remoto para as respostas dos usuários. Essa integração permite que médicos e hospitais tenham acesso remoto aos dados coletados, proporcionando uma visão abrangente da condição de saúde do usuário.

## Envio de Respostas para o Firebase

Após o usuário responder às perguntas sobre seus sintomas no display, as respostas são enviadas de forma segura para o Firebase. O sistema utiliza o serviço de banco de dados em tempo real do Firebase para armazenar as informações.

O código no ESP32 foi configurado para construir uma carga útil JSON contendo um ID único e as respostas do usuário. Esse JSON é enviado para o Firebase usando uma solicitação HTTP POST. O Firebase armazena esses dados de maneira estruturada para facilitar a análise e recuperação posterior.

## Acesso Remoto para Profissionais de Saúde

Médicos e profissionais de saúde podem acessar os dados armazenados no Firebase remotamente. Isso oferece a eles a capacidade de monitorar continuamente a condição do paciente e tomar decisões informadas com base nas respostas fornecidas. O acesso remoto é essencial para fornecer orientações rápidas e eficazes, garantindo um cuidado de saúde eficiente.

Essa abordagem inovadora não apenas simplifica o monitoramento pós-hospitalar, mas também fornece uma solução acessível e eficaz para a avaliação remota da saúde do paciente.
