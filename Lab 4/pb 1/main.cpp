#include <iostream>
#include "Sort.h"

int main() {
	std::cout << "Sortarea primului obiect" << "\n";
	Sort sortare1("60,20,30,90,10"); //char *
	sortare1.QuickSort(0, sortare1.GetElementsCount() - 1, false);
	sortare1.Print();
	std::cout << "\n";
	std::cout << sortare1.GetElementFromIndex(3) << "\n";
	std::cout << sortare1.GetElementsCount() << "\n";

	std::cout << "Sortare pentru oboiectul 2" << "\n";
	Sort sortare2(5, 1, 9); //count, min value, max value
	sortare2.BubbleSort(true);
	sortare2.Print();
	std::cout << "\n";

	std::cout << "Sortarea obiectului 3" << "\n";
	Sort sortare3(5, 2, 4, 1, 3, 7); //count ...
	sortare3.InsertSort(true);
	sortare3.Print();
	std::cout << "\n";

	std::cout << "Sortare obiectului 4" << "\n";
	int* v = new int[5] {1, 2, 9, 0, 4};
	Sort sortare4(v, 5);
	sortare4.Print();
	std::cout << "\n";


	return 0;
}