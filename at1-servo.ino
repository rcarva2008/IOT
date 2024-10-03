// biblioteca do servo motor
#include <Servo.h>

// criando objeto do tipo servo Motor
Servo objetoservo;

// variável para salvar a porta que o servo está
int servo = 2;

// variáveis para as portas dos botões
int butaoAvancar = 4;  // botão para avançar
int butaoRecuar = 5;   // botão para recuar

// variável para posição do motor
int posicao = 0;

void setup()
{
  // inicializando o servo na porta digital 2
  objetoservo.attach(servo);
 
  // servo começa na posição zero
  objetoservo.write(posicao);
 
  // definir botões como entrada
  pinMode(butaoAvancar, INPUT);
  pinMode(butaoRecuar, INPUT);
}

void loop()
{
  // Se o botão de avançar for pressionado e a posição do servo estiver menor que 180
  if (digitalRead(butaoAvancar) == HIGH && posicao < 180) {
    // Aumente 1° de posição
    posicao++;
    // Mande o motor para a nova posição
    objetoservo.write(posicao);
    // Aguarde 1 segundo para a próxima leitura
    delay(1000);
  }

  // Se o botão de recuar for pressionado e a posição do servo estiver maior que 0
  if (digitalRead(butaoRecuar) == HIGH && posicao > 0) {
    // Diminua 1° de posição
    posicao--;
    // Mande o motor para a nova posição
    objetoservo.write(posicao);
    // Aguarde 1 segundo para a próxima leitura
    delay(1000);
  }
}

