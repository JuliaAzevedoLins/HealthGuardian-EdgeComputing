#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <DHTesp.h>

#define TFT_DC 2
#define TFT_CS 15
#define BTN_PIN_01 14 // Pino para o primeiro botão
#define BTN_PIN_02 12 // Pino para o segundo botão
#define DHT_PIN 15 // Pino de conexão do sensor DHT22
#define POTENTIOMETER_PIN 32
DHTesp dht;


int questao = 1;
int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float temperatura;
String pacientePressao;
String pacienteID;

const char* ssid = "Wokwi-GUEST";
const char* password = "";

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

// Função para gerar um ID único

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  dht.setup(15,DHTesp::DHT22);
  pinMode(POTENTIOMETER_PIN, INPUT);

  temperatura = dht.getTemperature();
  pacienteID = gerarID();
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("Conectado ao WiFi");
  pacientePressao = lerPressao();

  pinMode(BTN_PIN_01, INPUT_PULLUP);
  pinMode(BTN_PIN_02, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(1);

  // Exibe a mensagem de boas-vindas
  tft.setCursor(0, 90);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
  tft.println("Bem vindo ao");

  tft.setCursor(0, 130);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("HealthGuardian");

  delay(4000); 

  //Exibe a temperatura do paciente para o médico
  Serial.print("A temperatura do paciente é: ");
  Serial.print(temperatura);

  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 80);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.print("Sua temperatura:");

  
  tft.setCursor(0, 120);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.print(temperatura);
  tft.print(" C");
  delay(5000); 

  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 80);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.print("Sua pressao esta:");

  
  tft.setCursor(0, 120);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.print(pacientePressao);
  delay(5000); 

  // Exibe a mensagem para responder às perguntas
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 80);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("Por favor");

  tft.setCursor(0, 120);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("responda");

  tft.setCursor(0, 160);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("essas perguntas");

  delay(5000); // Aguarda 5 segundos antes de exibir a primeira pergunta
  questao_01();
}

String gerarID() {
  return "paciente" + String(random(1000, 9999));
}

String lerPressao() {
  // Leia o valor do potenciômetro (0-4095)
  int valorPotenciometro = analogRead(POTENTIOMETER_PIN);

  // Mapeie o valor do potenciômetro para um dos três estados: alta, normal, baixa
  if (valorPotenciometro < 1365) {
    return "alta";
  } else if (valorPotenciometro >= 1365 && valorPotenciometro < 2730) {
    return "normal";
  } else {
    return "baixa";
  }
}
// Função para exibir a primeira pergunta
void questao_01() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Voce esta");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("com febre?");
}

// Funções para exibir as demais perguntas
void questao_02() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Esta com");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("dores no corpo?");
}

void questao_03() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Dificuldade");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("para respirar?");
}

void questao_04() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Esta com tosse");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("persistente?");
}

void questao_05() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Voce esta");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("com coriza?");
}

void questao_06() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Voce esta com");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("dor de garganta?");
}

void questao_07() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Existe fadiga");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("persistente?");
}

void questao_08() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Voce percebe uma");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("perda de paladar?");
}

void questao_09() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Houve mudanca");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("no olfato?");
}

void questao_10() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("Voce teve");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("nausea?");
}
// Função para exibir mensagem final
void Acabou() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    
    if (countSim() > 5) {
      tft.setCursor(0, 40);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);
        tft.println("Enviamos suas respostas");

        tft.setCursor(0, 80);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);
        tft.println("para o seu medico!");

        tft.setCursor(0, 120);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);
        tft.println("Por favor, retorne ");

        tft.setCursor(0, 160);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(3);
        tft.println("ao hospital");

        delay(5000);
        agradecimento();
        delay(5000);
        finalizacao();

    } else {
      tft.fillScreen(ILI9341_BLACK);
        tft.setCursor(0, 80);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);
        tft.println("Continue realizando ");

        tft.setCursor(0, 120);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(3);
          tft.println("o tratamento!");

        // Adiciona um pequeno delay de 3 segundos antes de exibir a mensagem final
        delay(3000);
        agradecimento();
        delay(5000);
        finalizacao();

    }
}

// Função para contar o número de respostas "Sim"
int countSim() {
  int count = 0;
  for (int i = 0; i < 10; i++) {
    if (array[i] == 1) {
      count++;
    }
  }
  return count;
}

// Função de finalização
void finalizacao() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 80);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("HealthGuardian");

  tft.setCursor(0, 120);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(4);
        tft.println("agradece :)");
}

// Função de agradecimento
void agradecimento(){
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 80);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println("Obrigado por responder");

  tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.println("as perguntas! Ate mais :)");
}

void loop() {
  if (questao <= 10) {
    if (digitalRead(BTN_PIN_01) == LOW) {
      array[questao - 1] = 1;
    } else if (digitalRead(BTN_PIN_02) == LOW) {
      array[questao - 1] = 0;
    } else {
      return;
    }

    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);

    if (array[questao - 1] == 1) {
      tft.setCursor(40, 80);
      tft.println("Sim");
    } else {
      tft.setCursor(40, 80);
      tft.println("Nao");
    }

    questao++;
    delay(500);

    if (questao <= 10) {
      switch (questao) {
        case 2: questao_02(); break;
        case 3: questao_03(); break;
        case 4: questao_04(); break;
        case 5: questao_05(); break;
        case 6: questao_06(); break;
        case 7: questao_07(); break;
        case 8: questao_08(); break;
        case 9: questao_09(); break;
        case 10: questao_10(); break;
      }
    } else {
      enviarDados();
      return;
    }
  }
}
void enviarDados() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 80);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("Enviando dados...");
  Serial.print("\nEnviando dados para o Firebase...");

  tft.setCursor(0, 120);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("Aguarde :)");

  Serial.print("\nDigite esse ID em nosso site: ");
  Serial.println(pacienteID);

  // Configura e envia os dados para o servidor
  HTTPClient http;
  String url = "https://healthguardian-e9b30-default-rtdb.firebaseio.com/DadosHealth.json";
  http.begin(url);
  http.addHeader("Content-Type", "application/json");

  // Constrói a carga útil JSON com o ID dinâmico
  String payload = "{\"name\":\"" + pacienteID + "\",";

  
  String temperaturaString = String(temperatura);
  payload += "\"temperatura\":\"" + String(temperatura) + "\",";

  payload += "\"pressao\":\"" + pacientePressao + "\",";

  for (int i = 0; i < 10; i++) {
    payload += "\"questao" + String(i + 1) + "\": " + String(array[i]);
    if (i < 9) payload += ",";
}
payload += "}";

  // Envia a solicitação POST
  int httpResponseCode = http.POST(payload);

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  } else {
    Serial.print("Erro ao enviar a solicitação POST: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  Acabou(); // Exibe a mensagem final
  questao = 1; // Reseta o contador de perguntas
}