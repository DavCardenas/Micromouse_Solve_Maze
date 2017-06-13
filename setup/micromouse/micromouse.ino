#include <Encoder.h>
#include <Ultrasonido.h>
#include <Motores.h>

Encoder encoder(2);
Motores motores(5,6,9,10,45, &encoder);
Ultrasonido ultrasonido;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encoder.getPin_In()), isrFunc, RISING);
}

void loop() {

motores.setSpeed(0.35);
  if(ultrasonido.calcularDistancia(1) > 5){
      motores.move(1); // mover de frente
  }else{
    motores.stop();
    
    
    if(ultrasonido.calcularDistancia(2) > 15){
      motores.move(4);
    }else if(ultrasonido.calcularDistancia(2) > 15){
      motores.move(3);  
    }else{
      motores.move(2);  
    }

    
  }  
}

void move(){
  
}

void isrFunc(){
  Serial.println(encoder.getSteps());
  encoder.countSteps();
}
