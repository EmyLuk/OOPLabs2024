#include <iostream>
#include "Car.h"
#include "bmw.h"
#include "volvo.h"
#include "seat.h"
#include "fiat.h"
#include "rangeRover.h"
#include "circuit.h"
using namespace std;


int main()
{
	circuit c;
	c.SetLength(100);
	c.SetWeather(weather::Rain);
	c.AddCar(new volvo());
	c.AddCar(new bmw());
	c.AddCar(new seat());
	c.AddCar(new fiat());
	c.AddCar(new rangeRover());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}