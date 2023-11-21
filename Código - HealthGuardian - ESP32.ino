#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_DC 2
#define TFT_CS 15
#define BTN_PIN_01 14 // Pino para o primeiro botão
#define BTN_PIN_02 12 // Pino para o segundo botão

int questao = 1;
int array[5] = {0, 0, 0, 0, 0};

const char* ssid = "Wokwi-GUEST";
const char* password = "";

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

// Função para gerar um ID único
String gerarID() {
  return "paciente" + String(millis()); // Usando millis() para um ID único baseado no tempo
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("Conectado ao WiFi");

  pinMode(BTN_PIN_01, INPUT_PULLUP);
  pinMode(BTN_PIN_02, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(1);

  // Exibe a mensagem de boas-vindas
  tft.setCursor(0, 40);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
  tft.println("Bem vindo ao");

  tft.setCursor(0, 80);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("Health Guardian");

  // Exibe a mensagem para responder às perguntas
  tft.setCursor(0, 140);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println("Por favor responda");

  tft.setCursor(0, 160);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println("essas perguntas");

  delay(5000); // Aguarda 5 segundos antes de exibir a primeira pergunta
  questao_01();
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
    tft.println("Voce esta com");

    tft.setCursor(0, 120);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.println("coriza?");
}

// Função para exibir mensagem final
void Acabou() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    
    if (countSim() > 3) {
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
        tft.setTextSize(2);
        tft.println("ao hospital");

    } else {
        tft.setCursor(0, 80);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);
        tft.println("Continue realizando o");

        tft.setCursor(0, 120);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);
        tft.println("tratamento!");

        // Adiciona um pequeno delay de 3 segundos antes de exibir a mensagem final
        delay(3000);

        tft.setCursor(0, 80);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(3);
        tft.println("Obrigado por responder");

        tft.setCursor(0, 120);
        tft.setTextColor(ILI9341_WHITE);
        tft.setTextSize(2);
        tft.println("às perguntas! Até mais :)");
    }
}

// Função para contar o número de respostas "Sim"
int countSim() {
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (array[i] == 1) {
      count++;
    }
  }
  return count;
}

void loop() { 
  if (digitalRead(BTN_PIN_01) == LOW && questao <= 5) {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);
    tft.println("Sim");
    array[questao - 1] = 1;
    questao = questao + 1;
    // Verifica qual é a próxima pergunta a ser exibida
    if (questao == 2) {
      questao_02();
    } else if (questao == 3) {
      questao_03();
    } else if (questao == 4) {
      questao_04();
    } else if (questao == 5) {
      questao_05();
    } else if (questao > 5) {
      Serial.print("Enviando....");
      tft.fillScreen(ILI9341_BLACK);
      tft.setCursor(0, 80);
      tft.setTextColor(ILI9341_WHITE);
      tft.setTextSize(3);
      tft.println("Enviando dados...");

      // Configura e envia os dados para o servidor
      HTTPClient http;
      String url = "https://healthguardian-e9b30-default-rtdb.firebaseio.com/DadosHealth.json";
      http.begin(url);
      http.addHeader("Content-Type", "application/json");

      // Constrói a carga útil JSON com o ID dinâmico
      String payload = "{\"name\":\"" + gerarID() + "\",";
      for(int i = 0; i < 5; i++) {
        payload += "\"value" + String(i + 1) + "\": " + String(array[i]);
        if(i < 4) payload += ",";
      }
      payload += "}";
      
      // Envia a solicitação POST
      int httpResponseCode = http.POST(payload);

      if(httpResponseCode > 0) {
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
  }
  if (digitalRead(BTN_PIN_02) == LOW && questao <= 5) {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 80);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);
    tft.println("Nao");
    array[questao - 1] = 0;
    questao = questao + 1;
    // Verifica qual é a próxima pergunta a ser exibida
    if (questao == 2) {
      questao_02();
    } else if (questao == 3) {
      questao_03();
    } else if (questao == 4) {
      questao_04();
    } else if (questao == 5) {
      questao_05();
    } else if (questao > 5) {
      Serial.print("Enviando....");
      tft.fillScreen(ILI9341_BLACK);
      tft.setCursor(0, 80);
      tft.setTextColor(ILI9341_WHITE);
      tft.setTextSize(3);
      tft.println("Enviando dados...");

      // Configura e envia os dados para o servidor
      HTTPClient http;
      String url = "https://healthguardian-e9b30-default-rtdb.firebaseio.com/DadosHealth.json";
      http.begin(url);
      http.addHeader("Content-Type", "application/json");

      // Constrói a carga útil JSON com o ID dinâmico
      String payload = "{\"name\":\"" + gerarID() + "\",";
      for(int i = 0; i < 5; i++) {
        payload += "\"value" + String(i + 1) + "\": " + String(array[i]);
        if(i < 4) payload += ",";
      }
      payload += "}";
      
      // Envia a solicitação POST
      int httpResponseCode = http.POST(payload);

      if(httpResponseCode > 0) {
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
  }
}
