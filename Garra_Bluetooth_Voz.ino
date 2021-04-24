/*
 * Projeto: Braço Robótico controlado por Voz
 * Autor: Sandro Mesquita (@profsandromesquita)
 * Empresa: Arduino Ômega
 */
#include <Servo.h> // Chama a biblioteca do Servo
Servo garra, elevar, avancar, base; // nome dos servos

char comandoVoz; //Variável que recebe o texto vindo do aplicativo

void setup(){
  garra.attach(3); // Anexar o motor 01 ao pino 03 (GARRA)
  elevar.attach(5); // Anexar o motor 02 ao pino 05 (ELEVAÇÃO)
  avancar.attach(6); // Anexar o motor 03 ao pino 06 (AVANÇO)
  base.attach(9); // Anexar o motor 04 ao pino 09 (GIRO)

  //Setup da conexão serial USB com o computador
  Serial.begin(9600);
  //Posição inicial do Braço
  posInicial();
}

void loop(){
  if (Serial.available() >= 0 ){
    comandoVoz = Serial.read(); //Dado recebido do Aplicativo
    //Se o comando for a letra 'a', de avanção, o braço avança
    if (comandoVoz == 'a'){ 
      elevar.write(45);
      delay(10);
      avancar.write(130);
      delay(10);
      garra.write(30);
      delay(10);
    }
    //Se o comando for a letra 'l', de levantar, o braço levanta
    if (comandoVoz == 'l'){
      elevar.write(120);
      delay(10);
      avancar.write(60);
      delay(10);
      garra.write(0); //Escreve no servo o valor da posição
      delay(10);
    }
    //Se o comando for a letra 'd', de direita, o braço vira para direita
    if (comandoVoz == 'd') base.write(0);
    //Se o comando for a letra 'e', de esquerda, o braço vira para esquerda
    if (comandoVoz == 'e') base.write(180);
    //Se o comando for a letra 'i', de inicio, o braço vai para posição inicial
    if (comandoVoz == 'i') posInicial();
  }
}
//Função que posiciona o braço na posição inicial
void posInicial() {
  garra.write(0);
  elevar.write(90);
  avancar.write(90);
  base.write(90);
  delay(10);
}
