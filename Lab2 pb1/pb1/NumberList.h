#pragma once
class NumberList {
public:
    int numbers[10];
    int count;
public:
    void Init();
    bool Add(int x);
    void Sort();
    void Print();
};