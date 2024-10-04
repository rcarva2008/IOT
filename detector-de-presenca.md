# Introdução
Este projeto utiliza [componente principal] conectado ao [dispositivo controlador] para [função principal do sistema]. O sistema [explicação breve do funcionamento], permitindo [explicação do objetivo]. A implementação inclui [detalhe adicional] e pode ser expandida para incluir [possibilidades futuras].

## Componentes Usados

1 Arduino Uno – Microcontrolador utilizado para controlar o sistema.
1 Sensor PIR (Passive Infrared Sensor) – Responsável por detectar movimento ao captar mudanças na radiação infravermelha.
1 Buzzer Piezoelétrico – Dispositivo que emite som quando ativado, utilizado para sinalização sonora quando o sensor detecta movimento.
1 Protoboard – Utilizada para montar o circuito de forma temporária e sem a necessidade de solda.
6 Jumpers Macho-Macho – Cabos de conexão para ligar os componentes ao Arduino e entre si.4

## Montagem do Circuito

![Imagem do Circuito](detector-de-presenca.png)

## Explicação do Código

int sensorPIR = 3;
int buzzer = 5;

void setup()
{
  pinMode(sensorPIR,INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
 int detectarPresenca = digitalRead(sensorPIR);
  if(detectarPresenca == 1){
    tone(buzzer,264);
  }else{
    noTone(buzzer);
}
    }

## Definição das Variáveis

buzzer: Pino conectado ao buzzer para emitir som.
pirSensor: Pino conectado ao sensor PIR para detecção de movimento.
pirState: Variável que guarda o estado atual do sensor (detectando ou não movimento).
val: Armazena o valor de leitura do sensor PIR.

## Funções Principais

setup(): Configura os pinos do buzzer e do sensor PIR como saída e entrada, respectivamente, e inicializa a comunicação serial.
loop(): Verifica o estado do sensor PIR e, caso detecte movimento, aciona o buzzer. Quando não há movimento, o buzzer é desligado.
