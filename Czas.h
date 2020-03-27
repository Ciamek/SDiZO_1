//
// Created by Maciej Ciura on 26.03.2020.
//

#include <windows.h>

#ifndef SDIZO_CZAS_H
#define SDIZO_CZAS_H


class Czas {
    double PCFreq = 0.0;
    __int64 CounterStart = 0;

public:
    Czas();

    void StartCounter();

    double GetCounter();
};


#endif //SDIZO_CZAS_H
