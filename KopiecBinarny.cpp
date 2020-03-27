//
// Created by Maciej Ciura on 18.03.2020.
//
#include <iostream>
#include <cmath>
#include <string>
#include "KopiecBinarny.h"




KopiecBinarny::KopiecBinarny(int size) {
    this->size = 0;
    tab = new int[size];
    rightCorner = leftCorner = bar = " ";
    rightCorner [ 0 ] = char(218);
    leftCorner [ 0 ] = char(192);
    bar [ 0 ] = char(179);


}

KopiecBinarny::~KopiecBinarny() {
    delete[] tab;
}

void KopiecBinarny::push(int value) {
    //if(this->checkIfPresent(value)) return;
        tab[size] = value;
        int pos = size;
        int parentPos = (pos - 1) /2;
        while(parentPos >= 0 && tab[pos] > tab[parentPos])
            {
            int tmp = tab[pos];
            tab[pos] = tab[parentPos];
            tab[parentPos] = tmp;
            pos = parentPos;
            parentPos = (pos - 1) /2;
            }
        size++;
}

void KopiecBinarny::pop() {

        if(size--)
        {
            int v = tab [ size ];
            int i = 0;
            int j = 1;

            while( j < size )
            {
                if( j + 1 < size && tab [ j + 1 ] > tab [ j ] ) j++;
                if( v >= tab [ j ] ) break;
                tab [ i ] = tab [ j ];
                i = j;
                j = 2 * j + 1;
            }

            tab [ i ] = v;

        }else std::cout<<"Nie ma takiego indeksu!"<<std::endl;
}

void KopiecBinarny::pop(int value) {

    int pos = checkIfPresent(value);
    if(pos != -1)
    {
        int v = tab [--size];
        int i = pos;
        int j = 2*pos + 1;

        while( j < size )
        {
            if( j + 1 < size && tab [ j + 1 ] > tab [ j ] ) j++;
            if( v >= tab [ j ] ) break;
            tab [ i ] = tab [ j ];
            i = j;
            j = 2 * j + 1;
        }
        tab [ i ] = v;
    }else std::cout<<"Nie ma takiego indeksu!"<<std::endl;
}

void KopiecBinarny::print() {
    std::cout<<"Tablica kopca:"<<std::endl;
    for(int i = 0; i < size ; i++)
        std::cout<<tab[i]<<' ';
    std::cout<<std::endl;
    printGraphic("","",0);
}





bool KopiecBinarny::checkIfPresent(int value) {
    for(int i=0; i < size; i++)
    {
        if(tab[i]==value)
            return true;
    }
    return false;
}

int KopiecBinarny::getSize() {
    return size;
}

void KopiecBinarny::printGraphic(const std::string& spaces, std::string corner, int pos) {
    //Rekurencyjny algorytm graficznego wypisywania kopca
    if(pos < size)
    {
        std::string newSpaces;

        newSpaces = spaces;
        int len = std::to_string(tab[pos]).length();  //Długość rodzica
        for(int i = 0; i<len;i++)                         //Dodawanie spacji
            newSpaces+= ' ';

        if( corner == rightCorner ) newSpaces [ newSpaces.length( ) - (len+1) ] = ' ';    //Usuwa zbędne poprzeczki
        printGraphic(newSpaces + bar,rightCorner, 2*pos + 2 );        //Prawy syn

        //Wypisywanie ostatecznego wciącia
        std::string toPrint = spaces;
        toPrint[toPrint.length()-1]=corner[0];
        std::cout<<toPrint<<tab[pos];
        if((2*pos+1)<size) std::cout<<char(180);std::cout<<std::endl;

        newSpaces = spaces;
        for(int i = 0; i<len;i++)    //Dodawanie spacji
            newSpaces+= ' ';

        if( corner == leftCorner ) newSpaces [ newSpaces.length( ) - (len+1) ] = ' ';     //Usuwa zbędne poprzeczki
        printGraphic(newSpaces + bar,leftCorner, 2*pos + 1 );         //Lewy syn
    }
}