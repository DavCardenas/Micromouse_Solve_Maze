#include <Arduino.h>
#include "Motores.h"

Motores::Motores(int pin_a_1, int pin_a_2, int pin_b_1, int pin_b_2){
	this-> pin_a_1 = pin_a_1;
	this-> pin_a_2 = pin_a_2;
	this-> pin_b_1 = pin_b_1;
	this-> pin_b_2 = pin_b_2;

	pinMode(this-> pin_a_1, OUTPUT);
	pinMode(this-> pin_a_2, OUTPUT);
	pinMode(this-> pin_b_1, OUTPUT);
	pinMode(this-> pin_b_2, OUTPUT);

	this-> speed = 1;
	Serial.begin(9600);
}

void Motores::move(int direction){
	if (direction == 1) // Frente
	 {
	 	this-> pwm_1 = (int) (0 * speed);
		this-> pwm_2 = (int) (255 * speed);
		this-> pwm_3 = (int) (255 * speed);
		this-> pwm_4 = (int) (0 * speed);
	 }else if (direction == 2) // Atras
	 {
	 	this-> pwm_1 = (int) (255 * speed);
		this-> pwm_2 = (int) (0 * speed);
		this-> pwm_3 = (int) (0 * speed);
		this-> pwm_4 = (int) (255 * speed);
	 }else if (direction == 3) // Derecha
	 {
	 	this-> pwm_1 = (int) (255 * speed);
		this-> pwm_2 = (int) (0 * speed);
		this-> pwm_3 = (int) (255 * speed);
		this-> pwm_4 = (int) (0 * speed);
	 }else if (direction == 4) //Izquierda
	 {
	 	this-> pwm_1 = (int) (0 * speed);
		this-> pwm_2 = (int) (255 * speed);
		this-> pwm_3 = (int) (0 * speed);
		this-> pwm_4 = (int) (255 * speed);
	 	
	 }

	analogWrite(pin_a_1, pwm_1);
  	analogWrite(pin_a_2, pwm_2);
  	analogWrite(pin_b_1, pwm_3);
  	analogWrite(pin_b_2, pwm_4);
}

void Motores::stop(){
	this-> pwm_1 = 255;
	this-> pwm_2 = 255;
	this-> pwm_3 = 255;
	this-> pwm_4 = 255;

	analogWrite(pin_a_1, pwm_1);
  	analogWrite(pin_a_2, pwm_2);
  	analogWrite(pin_b_1, pwm_3);
  	analogWrite(pin_b_2, pwm_4);
}

double Motores::getSpeed(){
	return this->speed;
}

void Motores::setSpeed(double spd){
	this->speed = spd;
}

Motores::~Motores(){
}
