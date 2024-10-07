# Projeto: motor de passo arduino

Este projeto utiliza um Arduino Uno conectado a um driver de motor de passo e um motor de passo controlado pela biblioteca AccelStepper.
O objetivo é controlar as rotações e o sentido de giro do motor de passo, com a possibilidade de ajustar a velocidade ea aceleração.
O sistema permite mover o motor em uma direção e, após completar o movimento, inverter a rotação.
Ele pode ser utilizado em diversas aplicações que envolvem movimento preciso e controlado,como impressoras 3D, máquinas CNC ou sistemas de automação.

## Componentes Usados

1 Arduino Uno: Microcontrolador responsável pelo controle do sistema.
1 Driver ULN2003: Driver utilizado para controlar o motor de passo.
1 Motor de Passo 28BYJ-48: Motor que realiza o movimento rotacional em passos controlados.
1 Protoboard: Utilizada para montar o circuito de forma temporária e sem a necessidade de solda.
5 Jumpers Macho-Macho: Cabos de conexão para ligar os componentes ao Arduino e entre si.

## Montagem do Circuito

![Imagem do Circuito](motor-de-passo-arduino.png)

## Explicação do Código

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

## Definição das Variáveis

voltas: Controla o número de passos para uma rotação completa. Pode ser ajustada para valores menores se forem necessários movimentos menores que 360°.
motor: Objeto responsável pelo controle do motor de passo, utilizando o método de controle FULL4WIRE, adequado para motores com 4 fios de controle.

## Funções Principais

setup(): Configura os parâmetros de velocidade e aceleração para o motor. É executada uma vez, quando o Arduino é ligado ou resetado.
loop(): Executa continuamente o movimento do motor, alternando entre movimentos em sentido horário e anti-horário, com uma pausa de 1 segundo entre os movimentos.
