#include <iostream>
#include <cmath>
#include "Math.h"

using namespace std;

int main() {
    char a[100] = {};
    char b[100] = {};
    char* res = Math::Add(a, b);
    cout << res;
    double x = 3.0;
    cout << Math::Add(1, 2) << '\n';
    cout <<Math::Add(5, 6, 7) << '\n';
    cout << Math::Add(5, 1, 2, 3, 4, 5) << '\n';
    cout << Math::Mul(1, 2) << '\n';
    cout << Math::Add(acos(-1), 3.5, 4.4) << '\n';
    cout  << Math::Mul(acos(-1), 3.5, 4.4) << '\n';
    cout << Math::Mul(3, 4, 5) << '\n';
    cout << Math::Mul(3.0, 2.0) << '\n';
    return 0;
}