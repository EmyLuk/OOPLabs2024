#pragma once
#include "Car.h"
#include "weather.h"
class circuit{
private:
	int length, nr_cars;
	car** cars;
	weather currentWeather;
public:
	circuit();
	~circuit();
	void SetLength(int length);
	void AddCar(car* car);
	void SetWeather(weather weather);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void Race();
};

