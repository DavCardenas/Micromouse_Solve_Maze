#include <Arduino.h>

class Motores
{

private: 
	int pin_a_1; // pin de conexion puente H para el primer motor
	int pin_a_2; // pin de conexion puente H para el primer motor
	int pin_b_1; // pin de conexion puente H para el segundo motor
	int pin_b_2; // pin de conexion puente H para el segundo motor

	// Variables de control de velocidad 
	int pwm_1; 
	int pwm_2;
	int pwm_3;
	int pwm_4;

	// porcentaje de velocidad (0 - 1)
	double speed;
	int toggles;
	int steps;
public:
	Motores(int pin_a_1, int pin_a_2, int pin_b_1, int pin_b_2, int toggles);
	~Motores();
	void move(int direction);
	void stop();
	double getSpeed();
	void setSpeed(double spd);
	void turnRigth();
	void turnLeft();
	void setToggles(int ammount);
	void setStep();
};
