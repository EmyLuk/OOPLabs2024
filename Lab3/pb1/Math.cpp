#include <cstdarg>
#include "Math.h"
#include <cstring>

int Math::Add(int a, int b) {
    return a + b;
}
int Math::Add(int a, int b, int c) {
    return a + b + c;
}
int Math::Add(double a, double b) {
    return (int)(a + b);
}
int Math::Add(double a, double b, double c) {
    return (int)(a + b + c);
}
int Math::Mul(int a, int b) {
    return a * b;
}
int Math::Mul(int a, int b, int c) {
    return a * b * c;
}
int Math::Mul(double a, double b) {
    return (int)(a * b);
}
int Math::Mul(double a, double b, double c) {
    return (int)(a * b * c);
}
char* Math::Add(const char* a, const char* b) {
    if (a == nullptr || b == nullptr)
        return nullptr;
    int sizeRes = (int)strlen(a) + (int)strlen(b) + 1;// +1 pentru caracterul nul la sfarsitul sirului concatenat
    char* res = new char[sizeRes];//aloc memorie pentru sirul concatenat de dimensiune sizeRes
    int c = 0;//evidenta pozitiei din sirul rezultat res
    for (int i = 0; a[i]; i++)
        res[c++] = a[i];
    for (int i = 0; b[i]; i++)
        res[c++] = b[i];
    res[c] = '\0';
    return res;
}

int Math::Add(int count, ...) {
    va_list vaList;
    int sum = 0;
    va_start(vaList, count);
    for (int i = 0; i < count; i++)
        sum += va_arg(vaList, int);
    va_end(vaList);
    return sum;
}