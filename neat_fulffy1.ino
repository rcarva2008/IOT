// Biblioteca para conexão serial do sensor
#include <SoftwareSerial.h>

// Variável do sensor
int sensor = A0;

void setup() {
  // Definir o sensor como entrada
  pinMode(sensor, INPUT);
  // Utilizando o monitor serial
  Serial.begin(9600);
}

void loop() {
  // Guardar o valor lido pelo sensor
  int umidade = analogRead(sensor);
 
  // Imprimindo o valor lido
  Serial.print("Umidade do solo: ");  
  Serial.println(umidade);
 
  // Classificação da umidade do solo
  if (umidade >= 0 && umidade <= 300) {
    Serial.println("Solo seco");
  } else if (umidade > 300 && umidade <= 500) {
    Serial.println("Solo ideal");
  } else if (umidade > 500) {
    Serial.println("Solo úmido");
  }

  delay(10000); // Espera 10 segundos
}
