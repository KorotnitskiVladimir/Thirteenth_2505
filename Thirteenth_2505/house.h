//
//  house.h
//  house
//
//  Created by Коротницкий Владимир on 28.05.2024.
//

#ifndef house_h
#define house_h
#include <iostream>
using namespace std;

class Human
{
private:
    char* name;
public:
    Human(): name{nullptr} {}
    Human(const char* n)
    {
        name = new char[strlen(n)+1];
        strcpy_s(this->name, strlen(n)+1, n);
    }
    Human(const Human &obj)
    {
        name = new char[strlen(obj.name)+1];
        strcpy_s(this->name, strlen(obj.name)+1, obj.name);
    }
    ~Human()
    {
        delete [] name;
    }
    void setName();
    char* getName();
    void copyName(const Human &obj);
};

void Human::setName()
{
    char buff[50];
    gets_s(buff);
    if (strlen(buff)>0)
    {
        name = new char[strlen(buff)+1];
        strcpy_s(name, strlen(buff)+1, buff);
    }
}

char* Human::getName()
{
    return name;
}

void Human::copyName(const Human &obj)
{
    this->name = new char[strlen(obj.name)+1];
    strcpy_s(this->name, strlen(obj.name)+1, obj.name);
}

class Apartment
{
private:
    Human* arr;
    int size;
    int number;
public:
    Apartment(): arr{nullptr}, size{0}, number{0} {}
    Apartment(Human* a, int s, int n)
    {
        this->number = n;
        this->size = s;
        arr = new Human[size];
        for (int i=0; i<size; i++)
            this->arr[i].copyName(a[i]);
    }
    Apartment(const Apartment &obj)
    {
        this->number = obj.number;
        this->size = obj.size;
        this->arr = new Human[size];
        for (int i=0; i<size; i++)
            this->arr[i].copyName(obj.arr[i]);
    }
    ~Apartment()
    {
        delete [] arr;
    }
    void showApt();
    void addHuman(const Human &obj);
    void removeHuman(int p);
    void setNumber(int n);
    void copyApt(const Apartment &obj);
};

void Apartment::showApt()
{
    cout << "Apartment number " << number << " has below people living in: " << endl;
    for (int i=0; i<this->size; i++)
        cout << arr[i].getName() << endl;
}

void Apartment::addHuman(const Human &obj)
{
    Human* t = new Human[size+1];
    for (int i=0; i<size; i++)
        t[i].copyName(arr[i]);
    t[size].copyName(obj);
    delete [] arr;
    arr = t;
    size++;
}

void Apartment::removeHuman(int p)
{
    Human* t = new Human[size-1];
    for (int i=0; i<p; i++)
        t[i].copyName(arr[i]);
    for (int i=p, j=p+1; i<size-1; i++, j++)
        t[i].copyName(arr[j]);
    delete [] arr;
    arr = t;
    size--;
}

void Apartment::setNumber(int n)
{
    if (n>0)
        number = n;
}

void Apartment::copyApt(const Apartment &obj)
{
    this->number = obj.number;
    this->size = obj.size;
    this->arr = new Human[size];
    for (int i=0; i<size; i++)
        this->arr[i].copyName(obj.arr[i]);
}

class House
{
private:
    Apartment* array;
    int number;
    int size;
public:
    House(): array{nullptr}, number{0}, size{0} {}
    House(Apartment* a, int s, int n)
    {
        number = n;
        size = s;
        array = new Apartment[size];
        for (int i=0; i<size; i++)
            array[i].copyApt(a[i]);
    }
    House(const House &obj)
    {
        this->number = obj.number;
        this->size = obj.size;
        this->array = new Apartment[size];
        for (int i=0; i<size; i++)
            array[i].copyApt(obj.array[i]);
    }
    ~House()
    {
        delete [] array;
    }
    void setNumber(int n);
    void showHouse();
};

void House::setNumber(int n)
{
    if (n>0)
        number = n;
}

void House::showHouse()
{
    cout << "House number " << number << " has below apartments: " << endl;
    for (int i=0; i<size; i++)
        array[i].showApt();
}

#endif /* house_h */
