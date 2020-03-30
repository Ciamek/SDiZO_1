//
// Created by Maciej Ciura on 26.03.2020.
//

#ifndef SDIZO_DRZEWO_H
#define SDIZO_DRZEWO_H

struct ElementDrzewa{
       ElementDrzewa *parent;
       ElementDrzewa *left;
       ElementDrzewa *right;
    char color;
    int value;
};

class Drzewo {
public:
    std::string rightCorner, leftCorner, bar;
    ElementDrzewa *root;
    Drzewo();
    ~Drzewo();
    void push(int);

    void deleteElement(int);

    void deleteAll();

    void rotateLeft(ElementDrzewa *treeElement);
    void rotateRight(ElementDrzewa *treeElement);
    bool checkIfPresent(int);
    void printGraphic(const std::string &spaces, std::string corner, ElementDrzewa *pElementDrzewa);

    void print();

    int getSize();

private:

    ElementDrzewa guard{};
    int size;
    void deleteElement(ElementDrzewa *elementDrzewa);
    bool findVaule(int wartosc, ElementDrzewa *elementRoot);
    ElementDrzewa *findNextElement(ElementDrzewa *p);
    ElementDrzewa *findSmallestElement(ElementDrzewa *p);
    ElementDrzewa *findElement(int value);
};


#endif //SDIZO_DRZEWO_H
