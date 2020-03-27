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

    int size;

    Drzewo();

    ~Drzewo();

    void deleteAll();

    void push(int);

    void deleteElement(int);

    void rotateLeft(ElementDrzewa *treeElement);

    void rotateRight(ElementDrzewa *treeElement);

    bool checkIfPresent(int);

    void print(const std::string&, std::string, ElementDrzewa*);

    ElementDrzewa *root;
private:

    ElementDrzewa guard{};

    void usunElement(ElementDrzewa *);

    void findElement(int value, ElementDrzewa *elementRoot, ElementDrzewa *&soughtElement);

    bool findVaule(int wartosc, ElementDrzewa *elementRoot);

    ElementDrzewa *findNextElement(ElementDrzewa *p);

    ElementDrzewa *findSmallestElement(ElementDrzewa *p);
};


#endif //SDIZO_DRZEWO_H
