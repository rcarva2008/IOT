# Projeto de Semáforo com Sensor de Distância


Este projeto foi desenvolvido no Tinkercad, na disciplina de Internet das Coisas (IoT), para a
criação de um protótipo que simula um sistema de semáforo inteligente. O sistema controla os 
sinais de trânsito para veículos e pedestres, utilizando um sensor de distância para detectar
a presença de pedestres.

## Componentes Usados


- 1 Arduino Uno
- 1 Placa de Ensaio
- 6 LEDs (Vermelho, Amarelo e Verde para dois semáforos de veículos)
- 4 LEDs (Vermelho e Verde para dois semáforos de pedestres)
- 1 Sensor de Distância (Ultrassônico)
- 14 Jumpers Macho-Macho
- 3 Jumpers Macho-Fêmea


## Montagem do Circuito

![Imagem do Circuito](Avaliação.png)

## Explicação do Código



const int carRed1 = 4;
const int carYellow1 = 3;
const int carGreen1 = 2;
const int carRed2 = 7;
const int carYellow2 = 6;
const int carGreen2 = 5;

const int pedestrianRed1 = 9;
const int pedestrianGreen1 = 8;
const int pedestrianRed2 = 11;
const int pedestrianGreen2 = 10;

const int trigPin = 12;
const int echoPin = 13;

void setup() {
   LEDs dos carros
  pinMode(carRed1, OUTPUT);
  pinMode(carYellow1, OUTPUT);
  pinMode(carGreen1, OUTPUT);
  pinMode(carRed2, OUTPUT);
  pinMode(carYellow2, OUTPUT);
  pinMode(carGreen2, OUTPUT);

   LEDs dos pedestres
  pinMode(pedestrianRed1, OUTPUT);
  pinMode(pedestrianGreen1, OUTPUT);
  pinMode(pedestrianRed2, OUTPUT);
  pinMode(pedestrianGreen2, OUTPUT);

   Sensor de distância
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
   Inicia os semáforos
  startCarSignals();
}

void loop() {
  long duration, distance;
  
  Ativa o sensor de distância
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; cm

  if (distance < 50) {
    Pedestre detectado
    stopCarSignals();
    startPedestrianSignals();
    delay(15000); Espera 15 segundos
    stopPedestrianSignals();
    startCarSignals();
  }
}

void startCarSignals() {
  digitalWrite(carRed1, LOW);
  digitalWrite(carYellow1, LOW);
  digitalWrite(carGreen1, HIGH);
  digitalWrite(carRed2, LOW);
  digitalWrite(carYellow2, LOW);
  digitalWrite(carGreen2, HIGH);
}

void stopCarSignals() {
  digitalWrite(carRed1, HIGH);
  digitalWrite(carYellow1, LOW);
  digitalWrite(carGreen1, LOW);
  digitalWrite(carRed2, HIGH);
  digitalWrite(carYellow2, LOW);
  digitalWrite(carGreen2, LOW);
}

void startPedestrianSignals() {
  digitalWrite(pedestrianRed1, LOW);
  digitalWrite(pedestrianGreen1, HIGH);
  digitalWrite(pedestrianRed2, LOW);
  digitalWrite(pedestrianGreen2, HIGH);
}

void stopPedestrianSignals() {
  digitalWrite(pedestrianRed1, HIGH);
  digitalWrite(pedestrianGreen1, LOW);
  digitalWrite(pedestrianRed2, HIGH);
  digitalWrite(pedestrianGreen2, LOW);
}
