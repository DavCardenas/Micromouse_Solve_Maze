#include <Ultrasonido.h>
#include <Motores.h>

Motores motores(5,6,9,10);
Ultrasonido ultrasonido;
void setup() {
   Serial.begin(9600);
}

void loop() {
  motores.setSpeed(0.8);

  if(ultrasonido.calcularDistancia(1) > 20){
      motores.move(1); // mover de frente
  }else if(ultrasonido.calcularDistancia(2) > ultrasonido.calcularDistancia(3)){
   motores.move(4); // mover izquierda
  }else if(ultrasonido.calcularDistancia(3) > ultrasonido.calcularDistancia(2)){
   motores.move(3); // mover derecha
  }else{
     motores.move(2);
  }
  Serial.print(ultrasonido.calcularDistancia(1));
}
