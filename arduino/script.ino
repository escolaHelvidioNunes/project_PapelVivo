// =====================================================
// ESTUFA PARA SECAGEM DE PAPEL SEMENTE
// ARDUINO + DHT22 + 1 RELÉ + 2 LÂMPADAS
// =====================================================

#include <DHT.h>

// ===== SENSOR =====
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// ===== RELÉ =====
#define RELE 8

// ===== TEMPERATURAS =====
float tempLiga = 40.0;     // Liga abaixo disso
float tempDesliga = 45.0;  // Desliga acima disso

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(RELE, OUTPUT);

  // Relé começa desligado
  digitalWrite(RELE, HIGH);

  Serial.println("Estufa iniciada");

}

void loop() {

  // Ler temperatura
  float temperatura = dht.readTemperature();

  // Verifica erro no sensor
  if (isnan(temperatura)) {

    Serial.println("Erro ao ler sensor DHT22");
    delay(2000);
    return;

  }

  // Mostrar temperatura
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // ===== CONTROLE DAS LÂMPADAS =====

  // Liga as lâmpadas
  if (temperatura < tempLiga) {

    digitalWrite(RELE, LOW);

    Serial.println("Lampadas LIGADAS");

  }

  // Desliga as lâmpadas
  if (temperatura > tempDesliga) {

    digitalWrite(RELE, HIGH);

    Serial.println("Lampadas DESLIGADAS");

  }

  // Espera 2 segundos
  delay(2000);

}