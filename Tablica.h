//
// Created by Maciej Ciura on 14.03.2020.
//

#ifndef SDIZO_TABLICA_H
#define SDIZO_TABLICA_H

class Tablica {

private:
    int *head;
    int size;

public:
    Tablica();
    ~Tablica();

    void pushFront(int value);
    void pushBack(int value);
    void popFront();
    void popBack();
    void pushAny(int value, int pos);
    void popAny(int pos);
    int getSize();

    int &operator [] (int el){
        return this->head[el];
    }

    int checkIfPresent(int vaule);

    void print();
};


#endif //SDIZO_TABLICA_H
