//variaveis
int led =3;
int sensorluminosidade= A0;
// variavel para capturar a luminosidade
int luz =0; 

void setup()
{
  // led é de saida
  pinMode(led,OUTPUT);
  // sensor é de entrada
  pinMode(sensorluminosidade,INPUT);
}

void loop()
{
  // capturar o que o sensor leu no ambiente
  // analogRead é usado para leitura analogica
  
  luz = analogRead(sensorluminosidade);
  /* as portas analogicas capturam dados que variam
   de 0 até 1023 */
  
  // SE ESTIVER COM POUCA LUZ NO AMBIENTE
   if(luz<500){ 
  }if(luz>500 & luz<900){
    //digitalWrite(led,HIGH); // LIGAR LED
    analogWrite(led,500);
   }else{ // SE TIVER LUZ
    digitalWrite(led,LOW); // DESLIGAR LED
  }
  }

  
