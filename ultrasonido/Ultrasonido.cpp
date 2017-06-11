#include <Arduino.h>
#include "Ultrasonido.h"

Ultrasonido::Ultrasonido(){

	this->distancia = 0;
  	this->tiempo = 0;

	pinMode(A2,OUTPUT);
	pinMode(A3,INPUT);
	pinMode(A4,OUTPUT);
	pinMode(A5,INPUT);
	pinMode(7,OUTPUT);
	pinMode(8,INPUT);

	Serial.begin(9600);
}

int Ultrasonido::calcularDistancia(int sensor){
  	switch(sensor){
  		case 1: // Frontal
  			digitalWrite(A4,LOW);
      		delayMicroseconds(5);
     		digitalWrite(A4, HIGH); /* envío del pulso ultrasónico*/
      		delayMicroseconds(10);
     		tiempo=pulseIn(A5, HIGH);
      		distancia= int(0.017*tiempo);
      		Serial.println("Distancia ");
      		Serial.println(distancia);
      		Serial.println(" cm");
  		break;
  		case 2: // Izquierda
  			digitalWrite(7,LOW);
      		delayMicroseconds(5);
     		digitalWrite(7, HIGH); /* envío del pulso ultrasónico*/
      		delayMicroseconds(10);
     		tiempo=pulseIn(8, HIGH);
      		distancia= int(0.017*tiempo);
      		Serial.println("Distancia ");
      		Serial.println(distancia);
      		Serial.println(" cm");
  		break;
  		case 3: // Derecha
  			digitalWrite(A2,LOW);
      		delayMicroseconds(5);
     		digitalWrite(A2, HIGH); /* envío del pulso ultrasónico*/
      		delayMicroseconds(10);
     		tiempo=pulseIn(A3, HIGH);
      		distancia= int(0.017*tiempo);
      		Serial.println("Distancia ");
      		Serial.println(distancia);
      		Serial.println(" cm");
  		break;
  	}

  	return distancia;
}

Ultrasonido::~Ultrasonido(){
}

