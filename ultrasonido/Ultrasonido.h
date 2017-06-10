#include <Arduino.h>
class Ultrasonido
{
private:
	int distancia;
  	long tiempo;
public:
	Ultrasonido();
	~Ultrasonido();
	int calcularDistancia(int sensor);
};