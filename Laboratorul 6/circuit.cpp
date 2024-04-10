#include "circuit.h"
#include "weather.h"
#include <iostream>

circuit::circuit() {
	this->nr_cars = 0;
	this->length = 0;
	this->cars = new car * [5];
	this->currentWeather = soare;
}

circuit::~circuit() {
	delete[] this->cars;
}

void circuit::SetLength(int length) {
	this->length = length;
}

void circuit::AddCar(car* car) {
	this->nr_cars++;
	this->cars[this->nr_cars - 1] = car;
	if (this->currentWeather == ninge) {
		this->cars[this->nr_cars - 1]->viteza = car->pe_iarna;
	}
	else if (this->currentWeather == ploua) {
		this->cars[this->nr_cars - 1]->viteza = car->pe_ploaie;
	}
	else {
		this->cars[this->nr_cars - 1]->viteza = car->pe_soare;
	}
}

void circuit::SetWeather(weather weather) {
	this->currentWeather = weather;
}

void circuit::Race() {
	for (int i = 0; i < this->nr_cars; i++) {
		this->cars[i]->capacitate_rezervor = this->cars[i]->capacitate_rezervor - this->cars[i]->consum_rezervor;
	}
}

void circuit::ShowFinalRanks() {
	bool sort;
	do {
		sort = true;
		for (int i = 0; i < this->nr_cars - 1; i++) {
			if ((float)this->length / (float)this->cars[i]->viteza > (float)(this->length / (float)this->cars[i + 1]->viteza)) {
				std::cout << (float)this->length / (float)this->cars[i]->viteza << " " << (float)(this->length / (float)this->cars[i + 1]->viteza) << "\n";
				std::swap(this->cars[i], this->cars[i + 1]);
				sort = false;
			}
		}
	} while (!sort);
	for (int i = 0; i < this->nr_cars; i++) {
		std::cout << i + 1 << " : " << this->cars[i]->name << "\n";
	}
}



void circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < this->nr_cars; i++) {
		if (this->cars[i]->consum_rezervor < 0) {
			std::cout << this->cars[nr_cars]->name << " Didn't finish" << "\n";
		}
	}
}