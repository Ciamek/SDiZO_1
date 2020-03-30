//
// Created by Maciej Ciura on 18.03.2020.
//

#ifndef SDIZO_KOPIECBINARNY_H
#define SDIZO_KOPIECBINARNY_H


class KopiecBinarny {
private:
    int *tab;
    signed int size;
    std::string rightCorner, leftCorner, bar;

public:
     explicit KopiecBinarny(int);
    ~KopiecBinarny();
    void push(int);
    void pop();
    void pop(int);
    void print();
    bool checkIfPresent(int);
    int getSize();
    void printGraphic(const std::string&, std::string, int);
};


#endif //SDIZO_KOPIECBINARNY_H
