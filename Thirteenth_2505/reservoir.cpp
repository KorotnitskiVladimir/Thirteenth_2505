//
//  main.cpp
//  Thirteenth_2505
//
//  Created by Коротницкий Владимир on 27.05.2024.
//
#include "reservoir.h"

int main(int argc, const char * argv[])
{
    Reservoir r2("Sukhoi Liman", "lake", 2550, 1220, 80);
    r2.getReservoir();
    Reservoir r1 = r2;
    r1.getReservoir();
    Reservoir r3;
    r3.setReservoir();
    r3.getReservoir();
    Reservoir r4;
    r4.copyReservoir(r2);
    r4.getReservoir();
    cout << r2.square() << " square meters" << endl;
    cout << r2.capacity() << " cubic meters" << endl;
    Reservoir r5("Oleksandrovka Lake", "lake", 1200, 800, 30);
    r5.getReservoir();
    cout << r2.compareType(r2, r5) << endl;
    cout << r2.max(r2, r5) << endl;
    Reservoir a[] = {r2, r5};
    int s = 2;
    Reservoir* arr = nullptr;
    createArr(&arr, a, s);
    printArr(&arr, s);
    Reservoir r6("Black Sea", "sea", 125000, 63000, 850);
    addElement(&arr, r6, s);
    printArr(&arr, s);
    removeElement(&arr, s, 1);
    printArr(&arr, s);
    removeArr(&arr);
    
    return 0;
}
