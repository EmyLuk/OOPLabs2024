#include "global.h"
#include <iostream>
#include <cstring>

int compareBy_Name(Student* c1, Student* c2) {
	if (strcmp(c1->GetName(), c2->GetName()) > 0) {
		return 1;
	}
	else if (strcmp(c1->GetName(), c2->GetName()) == 0) {
		return 0;
	}
	else return -1;
}

int compareBy_Mathematics_Grade(Student* c1, Student* c2) {
	if (c1->Get_Mathematics_Grade() > c2->Get_Mathematics_Grade()) {
		return 1;
	}
	else if (c1->Get_Mathematics_Grade() == c2->Get_Mathematics_Grade()) {
		return 0;
	}
	else return -1;
}

int compareBy_English_Grade(Student* c1, Student* c2) {
	if (c1->Get_English_Grade() > c2->Get_English_Grade()) {
		return 1;
	}
	else if (c1->Get_English_Grade() == c2->Get_English_Grade()) {
		return 0;
	}
	else return -1;
}

int compareBy_History_Grade(Student* c1, Student* c2) {
	if (c1->Get_History_Grade() > c2->Get_History_Grade()) {
		return 1;
	}
	else if (c1->Get_History_Grade() == c2->Get_History_Grade()) {
		return 0;
	}
	else return -1;
}

int compareBy_Average_Grade(Student* c1, Student* c2) {
	if (c1->Get_Average_Grade() > c2->Get_Average_Grade()) {
		return 1;
	}
	else if (c1->Get_Average_Grade() == c2->Get_Average_Grade()) {
		return 0;
	}
	else return -1;
}