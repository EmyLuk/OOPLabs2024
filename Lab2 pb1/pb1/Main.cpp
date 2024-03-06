#include "NumberList.h"
#include <iostream>
using namespace std;

int main() {
    NumberList myClass{};
    myClass.Init();
    myClass.Add(3);
    myClass.Add(1);
    myClass.Add(10);
    myClass.Sort();
    myClass.Print();
 
}