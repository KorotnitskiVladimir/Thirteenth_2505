//
//  reservoir.h
//  Thirteenth_2505
//
//  Created by Коротницкий Владимир on 27.05.2024.
//

#include <iostream>
using namespace std;

class Reservoir
{
private:
    char* name;
    char* type;
    int lenght;
    int width;
    int depth;
public:
    Reservoir(): name{nullptr}, type{nullptr}, lenght{0}, width{0}, depth{0} {}
    Reservoir(const char* n, const char* t, int l, int w, int d)
    {
        this->name = new char[strlen(n)+1];
        strcpy_s(this->name, strlen(n)+1, n);
        this->type = new char[strlen(t)+1];
        strcpy_s(this->type, strlen(t)+1, t);
        this->lenght = l;
        this->width = w;
        this->depth = d;
    }
    Reservoir(const Reservoir &o)
    {
        name = new char[strlen(o.name)+1];
        strcpy_s(this->name, strlen(o.name)+1, o.name);
        type = new char[strlen(o.type)+1];
        strcpy_s(this->type, strlen(o.type)+1, o.type);
        this->lenght = o.lenght;
        this->width = o.width;
        this->depth = o.depth;
    }
    ~Reservoir()
    {
        delete[] name;
        delete[] type;
    }
    void setReservoir();
    void getReservoir();
    void copyReservoir(const Reservoir &o);
    int square();
    int capacity();
    bool compareType(Reservoir &a, Reservoir &b);
    int max(Reservoir &a, Reservoir &b);
};

void Reservoir::setReservoir()
{
    char buffer[50];
    int l, w, d;
    cout << "enter reservoir's name ->" << endl;
    gets_s(buffer);
    name = new char[strlen(buffer)+1];
    strcpy_s(this->name, strlen(buffer)+1, buffer);
    cout << "enter reservoir's type ->" << endl;
    gets_s(buffer);
    type = new char[strlen(buffer)+1];
    strcpy_s(this->type, strlen(buffer)+1, buffer);
    cout << "enter reservoir's lenght, width and depth ->" << endl;
    cin >> l >> w >> d;
    cin.ignore();
    if (l>0 && w>0 && d>0)
    {
        this->lenght = l;
        this->width = w;
        this->depth = d;
    }
}

void Reservoir::getReservoir()
{
    cout << "Reservoir: " << this->name << endl;
    cout << "type: " << this->type << endl;
    cout << "lenght: " << this->lenght << " meters" << endl;
    cout << "width: " << this->width << " meters" << endl;
    cout << "depth: " << this->depth << " meters" << endl << endl;
}

void Reservoir::copyReservoir(const Reservoir &o)
{
    name = new char[strlen(o.name)+1];
    strcpy_s(this->name, strlen(o.name)+1, o.name);
    type = new char[strlen(o.type)+1];
    strcpy_s(this->type, strlen(o.type)+1, o.type);
    this->lenght = o.lenght;
    this->width = o.width;
    this->depth = o.depth;
}

int Reservoir::square()
{
    return this->lenght*this->width;
}

int Reservoir::capacity()
{
    return this->lenght*this->width*this->depth;
}

bool Reservoir::compareType(Reservoir &a, Reservoir &b)
{
    if (strcmp(a.type, b.type)==0)
        return true;
    else
        return false;
}

int Reservoir::max(Reservoir &a, Reservoir &b)
{
    if (compareType(a, b)==1)
    {
        if (a.square()>b.square())
            return a.square();
        else
            return b.square();
    }
    else
        return -1;
}

void createArr(Reservoir** arr, const Reservoir* a, int s)
{
    *arr = new Reservoir[s];
    for (int i=0; i<s; i++)
        (*arr)[i].copyReservoir(a[i]);
}

void printArr(Reservoir** arr, int s)
{
    for (int i=0; i<s; i++)
        (*arr)[i].getReservoir();
}

void removeArr(Reservoir** arr)
{
    delete [] *arr;
}

void addElement(Reservoir** arr, Reservoir &obj, int &s)
{
    Reservoir* t = new Reservoir[s+1];
    for (int i=0; i<s; i++)
        t[i].copyReservoir((*arr)[i]);
    t[s].copyReservoir(obj);
    delete[] *arr;
    *arr = t;
    s++;
}

void removeElement(Reservoir** arr, int &s, int p)
{
    Reservoir* t = new Reservoir[s-1];
    for (int i=0; i<p; i++)
        t[i].copyReservoir((*arr)[i]);
    for (int i=p+1, j=p; i<s; i++, j++)
        t[j].copyReservoir((*arr)[i]);
    delete[] *arr;
    *arr = t;
    s--;
}
