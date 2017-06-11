#ifndef ENCODER_H
#define ENCODER_H
#endif
#include <Arduino.h>

class Encoder
{

private:

	int count;
	int pin_in;

public:
	Encoder(int pin_in);
	~Encoder();
	void countSteps();
	int getSteps();
	void setSteps(int ammount);
	int getPin_In();
};