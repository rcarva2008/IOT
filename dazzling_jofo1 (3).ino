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
  // LEDs dos carros
  pinMode(carRed1, OUTPUT);
  pinMode(carYellow1, OUTPUT);
  pinMode(carGreen1, OUTPUT);
  pinMode(carRed2, OUTPUT);
  pinMode(carYellow2, OUTPUT);
  pinMode(carGreen2, OUTPUT);

  // LEDs dos pedestres
  pinMode(pedestrianRed1, OUTPUT);
  pinMode(pedestrianGreen1, OUTPUT);
  pinMode(pedestrianRed2, OUTPUT);
  pinMode(pedestrianGreen2, OUTPUT);

  // Sensor de distância
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Inicia os semáforos
  startCarSignals();
}

void loop() {
  long duration, distance;
  
  // Ativa o sensor de distância
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // cm

  if (distance < 50) {
    // Pedestre detectado
    stopCarSignals();
    startPedestrianSignals();
    delay(15000); // Espera 15 segundos
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