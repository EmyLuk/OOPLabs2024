#include "Student.h"
#include <iostream>
#include <cstring>


void Student::SetName(const char* name) {
	strcpy_s(this->name, name);
}

char* Student::GetName() {
	return this->name;
}

void Student::Set_Mathematics_Grade(float grade)
{
	this->mathematics_grade = grade;
}

float Student::Get_Mathematics_Grade() {
	return this->mathematics_grade;
}

void Student::Set_English_Grade(float grade) {
	this->english_grade = grade;
}

float Student::Get_English_Grade() {
	return this->english_grade;
}

void Student::Set_History_Grade(float grade) {
	this->history_grade = grade;
}

float Student::Get_History_Grade() {
	return this->history_grade;
}

float Student::Get_Average_Grade() {
	float sum = this->mathematics_grade + this->english_grade + this->history_grade;
	sum /= 3;
	return sum;
}