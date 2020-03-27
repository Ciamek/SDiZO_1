//
// Created by Maciej Ciura on 26.03.2020.
//
#include "Czas.h"
#include "Test.h"
#include <iostream>
#include "Tablica.h"
#include "Lista.h"
#include "KopiecBinarny.h"
#include "Drzewo.h"

using namespace std;


void Test::testTablicy() {
    Czas czas;
    Tablica tablica;
    int wybor = 99;
    int wartosc;
    int pozycja;
    long long time;
    
    while (wybor != 0) {
        cout << "Wybierz funkcje tablicy:" << endl;
        cout << "    1. Dodaj na poczatek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usun pierwszy" << endl;
        cout << "    5. Usun ostatni" << endl;
        cout << "    6. Usun ktorykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablice" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;
        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                tablica.pushFront(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " << time << "ms" << endl;
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                tablica.pushBack(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                cout << "Podaj pozycje: ";
                cin >> pozycja;
                czas.StartCounter();
                tablica.pushAny(wartosc, pozycja);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 4:
                czas.StartCounter();
                tablica.popFront();
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 5:
                czas.StartCounter();
                tablica.popBack();
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 6:
                cout << "Podaj pozycje: ";
                cin >> pozycja;
                czas.StartCounter();
                tablica.popAny(pozycja);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 7:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                tablica.checkIfPresent(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 8:
                czas.StartCounter();
                tablica.print();
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;
        }

    }
}

void Test::testListy() {
    Czas czas;
    Lista lista;
    int wybor = 99;
    int wartosc;
    int pozycja;
    long long time;

    while (wybor != 0) {
        cout << "Wybierz funkcje listy:" << endl;
        cout << "    1. Dodaj na poczatek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usun pierwszy" << endl;
        cout << "    5. Usun ostatni" << endl;
        cout << "    6. Usun ktorykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj liste" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;
        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                lista.pushFront(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                lista.pushBack(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                cout << "Podaj pozycje: ";
                cin >> pozycja;
                czas.StartCounter();
                lista.pushAny(wartosc, pozycja);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 4:
                czas.StartCounter();
                lista.popFront();
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 5:
                czas.StartCounter();
                lista.popBack();
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 6:
                cout << "Podaj pozycje: ";
                cin >> pozycja;
                czas.StartCounter();
                lista.popAny(pozycja);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 7:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                lista.checkIfPresent(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 8:
                czas.StartCounter();
                lista.print();
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

        }

    }
}

void Test::testKopca() {
    Czas czas;
    KopiecBinarny kopiec(20);
    int wybor = 99;
    int wartosc;
    long long time;

    while (wybor != 0) {
        cout << "Wybierz funkcje Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usun" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;
        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                kopiec.push(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                kopiec.pop(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                kopiec.checkIfPresent(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 4:
                czas.StartCounter();
                kopiec.print();
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;
        }

    }
}

void Test::testDrzewa() {
    Czas czas;
    Drzewo drzewo;
    int wybor = 99;
    int wartosc;
    long long time;

    while (wybor != 0) {
        cout << "Wybierz funkcje Drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usun" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;
        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                drzewo.push(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                drzewo.deleteElement(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 3:
                cout << "Podaj wartosc: ";
                cin >> wartosc;
                czas.StartCounter();
                drzewo.checkIfPresent(wartosc);
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

            case 4:
                czas.StartCounter();
                cout << "NIE DZIAĹA" << endl;
                time = czas.GetCounter();
                cout << "Czas wykonania: " <<time<< "ms" << endl;
                break;

        }

    }
}
