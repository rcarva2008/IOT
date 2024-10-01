int buzzer = 3;
#define doo 262
#define re 294
#define mi 330
#define fa 349

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Função de ligar, tone()
  tone(buzzer, doo, 500); // tocar o do
  delay(600); // espere 600 milissegundos
  tone(buzzer, re, 500); // tocar o ré
  delay(600); // espere 600 milissegundos
  tone(buzzer, mi, 500); // tocar o mi
  delay(600); // espere 600 milissegundos
  tone(buzzer, fa, 500); // tocar o fa
  delay(600); // espere 600 milissegundos
 
  // Função de desligar, noTone()
  noTone(buzzer); // Desligar o som
  delay(2000); // Esperar 2 segundos antes de repetir
}

