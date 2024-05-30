#pragma once
#include <iostream>
#include <exception>
using namespace std;

class ArrayException : public exception
{
    virtual const char* what() const throw()
    {
        return "Array exception";
    }
};

class exceptie1 : public ArrayException
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};

class exceptie2 : public ArrayException
{
    virtual const char* what() const throw()
    {
        return "Capacitate depasita";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    T** list;

public:

    ArrayIterator(T** List, int start)
    {
        list = List;
        Current = start;
    }

    ArrayIterator& operator++()
    {
        Current++;
        return *this;
    }

    ArrayIterator& operator--()
    {
        Current--;
        return *this;
    }

    bool operator=(ArrayIterator<T>& other)
    {
        return list == other.list && Current == other.Current;
    }

    bool operator!=(ArrayIterator<T>& other)
    {
        return !(*this == other);
    }

    T* GetElement()
    {
        return list[Current];
    }


};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        List = nullptr;
        Capacity = 0;
        Size = 0;
    }
    ~Array() // destructor
    {
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        Capacity = capacity;
        Size = 0;
        if (Capacity < 0)
            throw ArrayException();
        List = new T * [Capacity];
    }
    Array(const Array<T>& otherArray) // constructor de copiere
    {
        List = new T * [Capacity];
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        for (int i = 0; i < Size; i++)
            List[i] = new T(*otherArray.List[i]);
    }
    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        if (index < 0 || index >= Size)
            throw exceptie1();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        if (Size >= Capacity)
            throw exceptie2();
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size)
            throw exceptie1();
        if (Size >= Capacity)
            throw exceptie2();
        for (int i = Size; i > index; i--)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size)
            throw exceptie1();
        if (Size >= Capacity)
            throw exceptie2();
        for (int i = Size - 1; i > index; i--)
            List[i + otherArray.Size] = List[i];
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size)
            throw exceptie1();
        delete List[index];
        for (int i = index; i < Size - 1; i++)
            List[i] = List[i + 1];
        Size--;
        return *this;

    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this == &otherArray)
            return true;
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(otherArray.List[i]);
        return true;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }

    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0)
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }


    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(*List[i], *List[j]) > 0)
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        int left, right, mid;
        left = 0;
        right = Size - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (*List[mid] == elem) return
                mid;
            else if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        int left, right, mid;
        left = 0;
        right = Size - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (compare(*List[mid], elem) == 0)
                return mid;
            else if (compare(*List[mid], elem) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        int left, right, mid;
        left = 0;
        right = Size - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (comparator->CompareElements(*List[mid], &elem) == 0)
                return mid;
            else if (comparator->CompareElements(*List[mid], &elem) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) // cauta un element in Array
    {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return 1;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return 1;
        return -1;
    }

    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(*List[i], &elem) == 0)
                return 1;
        return -1;
    }
    int GetSize()
    {
        return Size;
    }
    int GetCapacity()
    {
        return Capacity;
    }
    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, 0);
    }
    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(List, Size);
    }
};