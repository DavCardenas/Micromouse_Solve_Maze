#include <Encoder.h>
#include <Ultrasonido.h>
#include <Motores.h>

Encoder encoder(2);
Motores motores(5,6,9,10,1);
Ultrasonido ultrasonido;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encoder.getPin_In()), isrFunc, RISING);
}

void loop() {

motores.setSpeed(0.6);
//  if(ultrasonido.calcularDistancia(1) > 20){
//      motores.move(1); // mover de frente
//  }else if(ultrasonido.calcularDistancia(2) > ultrasonido.calcularDistancia(3)){
//   motores.move(4); // mover izquierda
//  }else if(ultrasonido.calcularDistancia(3) > ultrasonido.calcularDistancia(2)){
 //  motores.move(3); // mover derecha
 // }else{
   //  motores.move(2);
  //}

  motores.move(3); // mover derecha
  delay(2000);
  motores.move(4); // mover derecha
  delay(2000);
  //Serial.println(ultrasonido.calcularDistancia(3));
  
}

void isrFunc(){
  Serial.println("entra");
  encoder.countSteps();
  motores.setStep();
}
