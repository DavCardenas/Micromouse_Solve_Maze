#include <Arduino.h>
#include "Encoder.h"

Encoder::Encoder(int pin_in){
	this-> pin_in = pin_in;
	this-> count = 0;

	pinMode(pin_in, INPUT);
}

Encoder::~Encoder(){
}

void Encoder::countSteps(){
	this-> count = count + 1;
}

int Encoder::getSteps(){
	return this-> count;
}

void Encoder::setSteps(int ammount){
	this-> count = ammount;
}

int Encoder::getPin_In(){
	return this->pin_in;
}