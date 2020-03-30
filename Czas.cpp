//
// Created by Maciej Ciura on 26.03.2020.
//

#include "Czas.h"
#include <iostream>
#include <windows.h>

using namespace std;

Czas::Czas() {
    PCFreq = 0.0;
    CounterStart = 0;
}

void Czas::StartCounter() {

    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart) / 1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double  Czas::GetCounter()
{

    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}