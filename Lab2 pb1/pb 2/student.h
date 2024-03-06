#pragma once
class Student
{
	char name[100];
	float mathematics_grade, english_grade, history_grade;

public:
	void SetName(const char* name);
	char* GetName();

	void Set_Mathematics_Grade(float grade);
	float Get_Mathematics_Grade();

	void Set_English_Grade(float grade);
	float Get_English_Grade();

	void Set_History_Grade(float grade);
	float Get_History_Grade();

	float Get_Average_Grade();
};