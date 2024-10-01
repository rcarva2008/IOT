# Projeto de Buzzer com Notas Musicais

# Introdução
Este projeto utiliza um buzzer conectado ao Arduino para tocar uma sequência de notas musicais.
O sistema toca as notas "do", "ré", "mi" e "fa" em um intervalo definido, permitindo que se ouça
uma melodia simples. As notas são definidas por suas frequências em Hertz (Hz), e o código utiliza
funções para gerar os sons no buzzer.

# Componentes Usados

1 Arduino Uno

1 Buzzer Piezoelétrico

Jumpers Macho-Macho

# Montagem do Circuito

![Imagem do Circuito](notas-musicais.png)

# Explicação do Código

int buzzer = 3;                Pino conectado ao buzzer
#define doo 262                Frequência da nota do
#define re 294                 Frequência da nota ré
#define mi 330                  Frequência da nota mi
#define fa 349                 Frequência da nota fa

void setup() {
    pinMode(buzzer, OUTPUT);    Configura o pino do buzzer como saída
}

void loop() {
     Função de ligar, tone()
    tone(buzzer, doo, 500);      Tocar a nota do por 500 milissegundos
    delay(600);                  Espera 600 milissegundos
    tone(buzzer, re, 500);       Tocar a nota ré por 500 milissegundos
    delay(600);                  Espera 600 milissegundos
    tone(buzzer, mi, 500);       Tocar a nota mi por 500 milissegundos
    delay(600);                  Espera 600 milissegundos
    tone(buzzer, fa, 500);       Tocar a nota fa por 500 milissegundos
    delay(600);                  Espera 600 milissegundos
   
 Função de desligar, noTone()
 noTone(buzzer);              Desligar o som do buzzer
 delay(2000);                 Esperar 2 segundos antes de repetir
}
Definição das Variáveis
buzzer: Pino conectado ao buzzer para emitir sons.
doo, re, mi, fa: Frequências correspondentes às notas musicais.
Funções Principais
setup(): Configura o pino do buzzer como uma saída, permitindo que ele emita sons.
loop(): Toca cada nota musical em sequência, aguardando um intervalo de tempo específico entre cada nota e, ao final, desliga o som por um tempo antes de reiniciar a sequência.
Esse projeto é uma introdução divertida ao controle de som com o Arduino, e pode ser expandido para tocar melodias mais complexas ou interagir com outros componentes, como LEDs.
