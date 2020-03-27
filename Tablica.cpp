//
// Created by Maciej Ciura on 14.03.2020.
//
#include <iostream>
#include "Tablica.h"

using namespace std;

Tablica::Tablica() {
    head = nullptr;
    size = 0;
}

Tablica::~Tablica() {
        delete[] head;
}

void Tablica::pushFront(int value) {
    int *newHead = new int[size + 1];
    *newHead = value;

    for(int i=0;i < size; i++)
        newHead[i+1] = head[i];
    delete[] head;
    head = newHead;
    size++;
}

void Tablica::pushBack(int value) {
    int *newHead = new int[size + 1];
    int i;
    for(i=0; i < size; i++)
        newHead[i]=head[i];
    newHead[i] = value;
    delete[] head;
    head = newHead;
    size++;
}

void Tablica::popFront() {
    if(size>0)
    {
        int *newHead = new int[size-1];
        for(int i=0; i < size-1; i++)
            newHead[i]=head[i+1];
        delete[] head;
        head = newHead;
        size--;
    }
}

void Tablica::popBack() {
    if(size>0)
    {
        int *newHead = new int[size -1];
        for(int i=0; i < size-1; i++)
            newHead[i]=head[i];
        delete[] head;
        head = newHead;
        size--;
    }
}

void Tablica::pushAny(int value, int pos) {
    if(pos > size || pos < 0) {
        std::cout << "Blad! Brak pozycji w tablicy!";
        return;
    }
        int *newHead = new int[size +1];
        for(int i=0; i<pos; i++)
            newHead[i]=head[i];
        newHead[pos]=value;
        for(int i=pos;i<size;i++)
            newHead[i+1]=head[i];
        delete[] head;
        head = newHead;
        size++;

}

void Tablica::popAny(int pos) {
    if(pos > size -1 || pos < 0)
        std::cout<<"Blad! Brak pozycji w tablicy!";
    else
    {
        int *newHead = new int[size -1];
        for(int i=0; i<pos; i++)
            newHead[i]=head[i];

        for(int i=pos+1;i<size;i++)
            newHead[i-1]=head[i];
        delete[] head;
        head = newHead;
        size--;
    }
}

int Tablica::getSize() {
    return this->size;
}

bool Tablica::checkIfPresent(int value) {
    for (int i = 0; i < size; i++) {
        if (head[i] == value) {
            return true;
        }
    }
    return false;
}

void Tablica::print() {
    cout << "Aktualny stan tablicy:" << endl;
    if (head != nullptr) {
        for (int i = 0; i < size; i++) {
            cout << "{" << head[i] << "}"<<endl;
        }
    } else {
        cout << "    Tablica nie ma zadnych elementow" << endl;
    }
}




