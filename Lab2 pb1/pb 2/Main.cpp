#include <iostream>
#include "Student.h"
#include "global.h"
using namespace std;

int main()
{
	Student s1, s2;

	s1.SetName("Emi");
	s2.SetName("Gabi");

	s1.Set_Mathematics_Grade(9.5);
	s2.Set_Mathematics_Grade(8.5);

	s1.Set_History_Grade(9.2);
	s2.Set_History_Grade(9.8);

	s1.Set_English_Grade(7.2);
	s2.Set_English_Grade(8.2);

	if (compareBy_Name(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " este mai inaintat alfabetic" << "\n";
	}
	else if (compareBy_Name(&s1, &s2) == 0) {
		std::cout << "Sunt la fel alafabetic" << "\n";
	}
	else std::cout << s2.GetName() << " este mai inaintat alfabetic" << "\n";

	if (compareBy_Mathematics_Grade(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " are nota mai mare la mate" << "\n";
	}
	else if (compareBy_Mathematics_Grade(&s1, &s2) == 0) {
		std::cout << "Au aceeasi nota la mate" << "\n";
	}
	else std::cout << s2.GetName() << " are nota mai mare la mate" << "\n";

	if (compareBy_History_Grade(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " are nota mai mare la istorie" << "\n";
	}
	else if (compareBy_History_Grade(&s1, &s2) == 0) {
		std::cout << "Au aceeasi nota la istorie" << "\n";
	}
	else std::cout << s2.GetName() << " are nota mai mare la istorie" << "\n";

	if (compareBy_English_Grade(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " are nota mai mare la engleza" << "\n";
	}
	else if (compareBy_English_Grade(&s1, &s2) == 0) {
		std::cout << "Au aceeasi nota la engleza" << "\n";
	}
	else std::cout << s2.GetName() << " are nota mai mare la engleza" << "\n";

	if (compareBy_Average_Grade(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " are media mai mare" << "\n";
	}
	else if (compareBy_Average_Grade(&s1, &s2) == 0) {
		std::cout << "Au aceeasi medie" << "\n";
	}
	else std::cout << s2.GetName() << " are media mai mare" << "\n";

	return 0;
}