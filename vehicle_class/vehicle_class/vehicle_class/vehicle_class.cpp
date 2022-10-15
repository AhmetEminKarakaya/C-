#include <iostream>
#include "vehicle.h"

int main()
{
	Vehicle *ptr[] = { new Car(125.500, "bmw"), new MotorCycle(34.200,"Honda") };

	Car c1(255.4, "Audi");

	c1.startEngine();
	c1.increaseSpeed();

	c1.displayInformation();









}

