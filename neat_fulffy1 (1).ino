// incluir a biblioteca
#include <AccelStepper.h>
// conversão de gramas para steps
//360° = 1024
//180° = 512
//90° = 256
//60° = 170
//45° = 128

//variavel para controlar as voltas do motor
#define voltas 1024
//criando o objeto para controlar o motor
AccelStepper motor (AccelStepper::FULL4WIRE,8,10,9,11);

void setup()  {
 
// definir a velocidade maxima do motor
motor.setMaxSpeed(1000);
// definir a aceleração maxima do motor
motor.setAcceleration(100);


}

void loop()  {
// habilitar as portas de controle do motor no ardsuino
motor.run();
// fazer o motor se movimentar  a 360°/1824 passos
motor.moveTo(voltas);
// girar a sentido contrario
motor.moveTo(-motor.currentPosition());
delay(1000);
}