//
//  main.cpp
//  house
//
//  Created by Коротницкий Владимир on 28.05.2024.
//

#include "house.h"

int main(int argc, const char * argv[]) 
{
    Human h1("Korotnitski Vladimir");
    Human h2("Mosunov Aleksej");
    Human a[] = {h1, h2};
    Apartment a1(a, 2, 1);
    Human h3("Chantai Olena");
    Human h4("Barabash Iryna");
    Human b[] = {h3, h4};
    Apartment a2(b, 2, 2);
//    a1.showApt();
//    a2.showApt();
//    a2.setNumber(5);
//    a2.showApt();
    Apartment ar[] = {a1, a2};
    House obj(ar, 2, 9);
//    obj.showHouse();
//    obj.setNumber(12);
//    obj.showHouse();
    House obj2 = obj;
    obj2.setNumber(8);
    //obj2.showHouse();
    Human h5;
    h5.setName();
    cout << h5.getName() << endl;
    
    return 0;
}
