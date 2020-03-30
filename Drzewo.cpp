//
// Created by Maciej Ciura on 26.03.2020.
//
#include <iostream>
#include "Drzewo.h"
Drzewo::Drzewo() {

    size = 0;

    //Kolory drzewa okreĹ›lane jako " ", zanim sÄ… zdefiniowane

    //Inicjaliacja straĹĽnika
    guard.color = 'B';
    guard.parent = &guard;
    guard.left = &guard;
    guard.right = &guard;
    root = &guard;

    rightCorner = leftCorner = bar = " ";
    rightCorner [ 0 ] = char(218);// rightCorner [ 1 ] = 196;
    leftCorner [ 0 ] = char(192);// leftCorner [ 1 ] = 196;
    bar [ 0 ] = char(179);
}

Drzewo::~Drzewo() {
    if (root)
        deleteAll();
}

void Drzewo::deleteAll() {
    deleteElement(root);

    //Inicjalizacja straĹĽnika
    guard.color = 'B';
    guard.parent = &guard;
    guard.left = &guard;
    guard.right = &guard;
    root = &guard;


    //Ustaw rozmiar drzewa na 1
    Drzewo::size = 0;
}

void Drzewo::deleteElement(ElementDrzewa *elementDrzewa) {

    //JeĹĽeli element nie jest straĹĽnikiem, usuĹ„ jego dzieci
    //A nastepnie sam element
    if (elementDrzewa != &guard) {
        deleteElement(elementDrzewa->left);
        deleteElement(elementDrzewa->right);
        delete elementDrzewa;

        //Zmniejsz rozmiar drzewa
        Drzewo::size--;
    } else {

        std::cout << "Usuwany element jest straznikiem!" << std::endl;

    }
}

void Drzewo::rotateLeft(ElementDrzewa *treeElement) {

    ElementDrzewa *y, *p;

    y = treeElement->right;
    if (y != &guard) {
        p = treeElement->parent;
        treeElement->right = y->left;
        if (treeElement->right != &guard) treeElement->right->parent = treeElement;

        y->left = treeElement;
        y->parent = p;
        treeElement->parent = y;

        if (p != &guard) {
            if (p->left == treeElement) p->left = y; else p->right = y;
        } else root = y;
    }

}

void Drzewo::rotateRight(ElementDrzewa *treeElement) {

    ElementDrzewa *y, *p;

    y = treeElement->left;
    if (y != &guard) {
        p = treeElement->parent;
        treeElement->left = y->right;
        if (treeElement->left != &guard) treeElement->left->parent = treeElement;

        y->right = treeElement;
        y->parent = p;
        treeElement->parent = y;

        if (p != &guard) {
            if (p->left == treeElement) p->left = y; else p->right = y;
        } else root = y;
    }

}

void Drzewo::push(int wartosc) {

    ElementDrzewa *X, *Y;
    size++;
    //Stworzenie nowego wÄ™zĹ‚a dla drzewa
    X = new ElementDrzewa;
    X->left = &guard;
    X->right = &guard;
    X->parent = root;
    X->value = wartosc;

    //Przypisanie korzenia jako X, jeĹĽeli parrent jest straĹĽnikiem
    //W przeciwnym wypadku, zastÄ…pienie liĹ›cia
    if (X->parent == &guard) {
        root = X;
    } else {
        //PÄ™tla wyszukuje liĹ›Ä‡ do zastÄ…pienia przez X
        //ZaleĹĽnie od sytuacji zastÄ™puje prawy lub lewy liĹ›Ä‡ drzewa
        while (true) {
            //X zastÄ™puje lewy liĹ›Ä‡
            if (wartosc < X->parent->value) {
                if (X->parent->left == &guard) {
                    X->parent->left = X;
                    break;
                }
                X->parent = X->parent->left;

                // X zastÄ™puje prawy liĹ›Ä‡
            } else if (wartosc > X->parent->value) {
                if (X->parent->right == &guard) {
                    X->parent->right = X;
                    break;
                }
                X->parent = X->parent->right;

                //Brak moĹĽliwoĹ›ci zastÄ…pienia liĹ›cia
            } else {
                delete X;
                return;
            }
        }

        //Kolorowanie wÄ™zĹ‚a na czerwono
        X->color = 'R';
        while ((X != root) && (X->parent->color == 'R')) {
            if (X->parent == X->parent->parent->left) {
                Y = X->parent->parent->right;

                //Przypadek 1
                if (Y->color == 'R') {
                    X->parent->color = 'B';
                    Y->color = 'B';
                    X->parent->parent->color = 'R';
                    X = X->parent->parent;
                    continue;
                }

                //Przypadek 2
                if (X == X->parent->right) {
                    X = X->parent;
                    rotateLeft(X);
                }

                //Przypadek 3
                X->parent->color = 'B';
                X->parent->parent->color = 'R';
                rotateRight(X->parent->parent);
                break;

                //Przypadki lustrzane
            } else {
                Y = X->parent->parent->left;

                //Przypadek lustrzany 1
                if (Y->color == 'R') {
                    X->parent->color = 'B';
                    Y->color = 'B';
                    X->parent->parent->color = 'R';
                    X = X->parent->parent;
                    continue;
                }

                //Przypadek lustrzany 2
                if (X == X->parent->left) {
                    X = X->parent;
                    rotateRight(X);
                }

                //Przypadek lustrzany 3
                X->parent->color = 'B';
                X->parent->parent->color = 'R';
                rotateLeft(X->parent->parent);
                break;
            }
        }
        root->color = 'B';


    }
}

void Drzewo::deleteElement(int wartosc) {

    ElementDrzewa *elementToDelete = findElement(wartosc);


    ElementDrzewa *W, *Y, *Z;

    if ((elementToDelete->left == &guard) || (elementToDelete->right == &guard))
        Y = elementToDelete;
    else Y = findNextElement(elementToDelete);

    if (Y->left != &guard) Z = Y->left;
    else Z = Y->right;

    Z->parent = Y->parent;

    if (Y->parent == &guard) root = Z;
    else if (Y == Y->parent->left) Y->parent->left = Z;
    else Y->parent->right = Z;

    if (Y != elementToDelete) elementToDelete->value = Y->value;

    if (Y->color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
        while ((Z != root) && (Z->color == 'B'))
            if (Z == Z->parent->left) {
                W = Z->parent->right;

                //Przypadek 1
                if (W->color == 'R') {
                    W->color = 'B';
                    Z->parent->color = 'R';
                    rotateLeft(Z->parent);
                    W = Z->parent->right;
                }

                //Przypadek 2
                if ((W->left->color == 'B') && (W->right->color == 'B')) {
                    W->color = 'R';
                    Z = Z->parent;
                    continue;
                }

                //Przypadek 3
                if (W->right->color == 'B') {
                    W->left->color = 'B';
                    W->color = 'R';
                    rotateRight(W);
                    W = Z->parent->right;
                }

                //Przypadek 4
                W->color = Z->parent->color;
                Z->parent->color = 'B';
                W->right->color = 'B';
                rotateLeft(Z->parent);

                //ZakoĹ„czenie pÄ™tli
                Z = root;

                //Przypadki lustrzane} else {
                W = Z->parent->left;

                //Lustrzany przypadek 1
                if (W->color == 'R') {
                    W->color = 'B';
                    Z->parent->color = 'R';
                    rotateLeft(Z->parent);
                    W = Z->parent->left;
                }

                //Lustrzany przypadek 2
                if ((W->left->color == 'B') && (W->right->color == 'B')) {
                    W->color = 'R';
                    Z = Z->parent;
                    continue;
                }

                //Lustrzany przypadek 3
                if (W->left->color == 'B') {
                    W->right->color = 'B';
                    W->color = 'R';
                    rotateLeft(W);
                    W = Z->parent->left;
                }

                //Lustrzany przypadek 4
                W->color = Z->parent->color;
                Z->parent->color = 'B';
                W->left->color = 'B';
                rotateRight(Z->parent);

                //ZakoĹ„czenie pÄ™tli
                Z = root;
            }

    Z->color = 'B';

    delete Y;


}


ElementDrzewa *Drzewo::findElement(int value) {
    ElementDrzewa *p;

    p = root;
    while ((p != &guard) && (p->value != value))
        if (value < p->value) p = p->left;
        else p = p->right;
    if (p == &guard) return nullptr;
    return p;
}


bool Drzewo::checkIfPresent(int wartosc) {
    return findVaule(wartosc, this->root);
}

bool Drzewo::findVaule(int wartosc, ElementDrzewa *elementRoot) {

    if (elementRoot != &guard) {
        if (elementRoot->value == wartosc) {
            return true;
        }
        findVaule(wartosc, elementRoot->left);
        findVaule(wartosc, elementRoot->right);
        return false;
    } else return false;
}

void Drzewo::print() {
    if (size == 0) {
        std::cout << "Drzewo nie zawiera zadnych elementow" << std::endl;
        return;
    }

    printGraphic("", "", root);
}

void Drzewo::printGraphic(const std::string &spaces, std::string corner, ElementDrzewa *pElementDrzewa) {
    //Rekurencyjny algorytm graficznego wypisywania kopca

    if (pElementDrzewa != &guard) {
        std::string newSpaces;

        newSpaces = spaces;
        int len = std::to_string(pElementDrzewa->value).length();  //Długość rodzica
        for (int i = 0; i < len; i++)                                  //Dodawanie spacji
            newSpaces += ' ';

        if (corner == rightCorner) newSpaces[newSpaces.length() - (len + 1)] = ' ';    //Usuwa zbędne poprzeczki
        printGraphic(newSpaces + bar, rightCorner, pElementDrzewa->right);        //Prawy syn

        //Wypisywanie ostatecznego wciącia
        std::string toPrint = spaces;
        toPrint[toPrint.length() - 1] = corner[0];
        std::cout << toPrint << pElementDrzewa->value;
        if (pElementDrzewa->left != &guard || pElementDrzewa->right != &guard) std::cout << char(180);
        std::cout << std::endl;

        newSpaces = spaces;
        for (int i = 0; i < len; i++)    //Dodawanie spacji
            newSpaces += ' ';

        if (corner == leftCorner) newSpaces[newSpaces.length() - (len + 1)] = ' ';     //Usuwa zbędne poprzeczki
        printGraphic(newSpaces + bar, leftCorner, pElementDrzewa->left);          //Lewy syn
    }
}

ElementDrzewa *Drzewo::findNextElement(ElementDrzewa *p) {
    ElementDrzewa *nextElement;

    if (p != &guard) {
        if (p->right != &guard) return findSmallestElement(p->right);
        else {
            nextElement = p->parent;
            while ((nextElement != &guard) && (p == nextElement->right)) {
                p = nextElement;
                nextElement = nextElement->parent;
            }
            return nextElement;
        }
    }
    return &guard;
}

ElementDrzewa *Drzewo::findSmallestElement(ElementDrzewa *p) {
    if (p != &guard)
        while (p->left != &guard) p = p->left;
    return p;
}

int Drzewo::getSize() {
    return this->size;
}
