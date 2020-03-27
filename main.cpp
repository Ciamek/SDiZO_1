#include <iostream>
#include "Lista.h"
#include "Test.h"
#include "AutoTest.h"
#include "KopiecBinarny.h"
#include "Drzewo.h"

using namespace std;

int main() {
    //Inicjalizacja klasy testujacej
    Test test;
    AutoTest autoTest;
    int wybor = 99;
    string tn = "n";

    cout << "SDiZO, Projekt 1, Maciej Ciura, 248879" << endl << endl;

    Drzewo drzewo;
    drzewo.push(1);
    drzewo.push(2);
    drzewo.push(3);
    drzewo.push(4);
    drzewo.push(5);
    drzewo.push(6);
    drzewo.push(7);
    drzewo.push(8);
    drzewo.push(9);
    drzewo.push(10);
    drzewo.print("","",drzewo.root);


    //Poczatkowe menu wyboru
    while (wybor != 0) {
        system("CLS");
        cout << "Wybierz test:" << endl;
        cout << "    1. Tablica Dynamiczna" << endl;
        cout << "    2. Lista" << endl;
        cout << "    3. Kopiec Binarny" << endl;
        cout << "    4. Drzewo Czerowno-Czarne" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;

        //Zamknij, jezeli wybrano 0
        if (wybor == 0) return 0;

        cout << "Wczytac dane z pliku? (t/n): ";
        cin >> tn;
        system("CLS");
        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "[Test tablicy dynamicznej]" << endl<<endl;
                if (tn == "t") autoTest.testTablicy();
                else test.testTablicy();

                break;

            case 2:
                cout << "[Test listy]" << endl<<endl;
                if (tn == "t") autoTest.testListy();
                else test.testListy();
                break;

            case 3:
                cout << "[Test kopca binarnego]" << endl<<endl;
                if (tn == "t") autoTest.testKopca();
                else test.testKopca();
                break;

            case 4:
                cout << "[Test drzewa]" << endl<<endl;
                if (tn == "t") autoTest.testDrzewa();
                else test.testDrzewa();
                break;

        }
    }

    return 0;
}
