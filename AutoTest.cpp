//
// Created by Maciej Ciura on 26.03.2020.
//

#include "AutoTest.h"
#include <iostream>
#include <fstream>
#include "Czas.h"
#include "Tablica.h"
#include "Lista.h"
#include "KopiecBinarny.h"
#include "Drzewo.h"
#include <ctime>
#include <zconf.h>
#include <conio.h>

using namespace std;

void otworzPliki(ifstream &plikWejsciowy, ofstream &plikWyjsciowy, int &dataSize) {
    string daneWejsciowe, daneWyjsciowe;
    cout << "Nazwa pliku z danymi wejsciowymi: ";
    cin >> daneWejsciowe;
    cout << "Plik z wynikami testu: ";
    cin >> daneWyjsciowe;

    //Otworz pliki
    plikWejsciowy.open("Input/" + daneWejsciowe);
    plikWyjsciowy.open("Output/" + daneWyjsciowe, ios::out);
    //Sprawdz czy plik jest otwarty poprawnie
    if (plikWejsciowy.is_open()) {
        cout <<endl<< "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie znaleziono pliku! Sprobuj ponownie..." << endl << endl;
        otworzPliki(plikWejsciowy, plikWyjsciowy, dataSize);
        return;
    }

    if (plikWyjsciowy.is_open()) {
        cout << "Otwarto plik " << daneWyjsciowe << endl;
    } else {
        cout << "Nie znaleziono pliku! Sprobuj ponownie..." << endl << endl;
        otworzPliki(plikWejsciowy, plikWyjsciowy, dataSize);
        return;
    }
    plikWejsciowy >> dataSize;

}

void AutoTest::testTablicy() {
    srand(time(nullptr));
    Czas czas;
    Tablica tablica;
    int wybor = 99;
    int wartosc;
    double time;
    int dataSize = 0;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    otworzPliki(plikWejsciowy, plikWyjsciowy, dataSize);
    sleep(1);
    while (wybor != 0) {
        system("CLS");
        cout << "Wybierz funkcje tablicy:" << endl;
        cout << "  [1] Dodaj na poczatek" << endl;
        cout << "  [2] Dodaj na koniec" << endl;
        cout << "  [3] Dodaj gdziekolwiek" << endl;
        cout << "  [4] Usun pierwszy" << endl;
        cout << "  [5] Usun ostatni" << endl;
        cout << "  [6] Usun ktorykolwiek" << endl;
        cout << "  [7] Wyszukaj element" << endl;
        cout << "  [8] Wydrukuj tablice" << endl;
        cout << "  [0] Wyjscie" << endl << endl;
        fflush(stdin);
        wybor = getch() - 48;


        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                plikWejsciowy.close();
                plikWyjsciowy.close();
                return;

            case 1:

                plikWyjsciowy <<endl<< "Pomiar dodawania z przodu:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);
                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    tablica.pushFront(wartosc);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru

                    plikWyjsciowy << time << endl;
                }
                while (tablica.getSize() != 0) {
                    tablica.popFront();
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 2:
                plikWyjsciowy <<endl<< "Pomiar dodawania z tyłu:" << endl;

                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    tablica.pushBack(wartosc);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                while (tablica.getSize() != 0) {
                    tablica.popFront();
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;



            case 3:
                plikWyjsciowy <<endl<< "Pomiar dodawania w losowym miejscu:" << endl;

                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);


                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;

                    if(tablica.getSize()==0)
                    {
                        czas.StartCounter();
                        tablica.pushAny(wartosc, 0);
                        time = czas.GetCounter();
                    }else {//Wykonaj funkcje z pomiarem
                        czas.StartCounter();
                        tablica.pushAny(wartosc, 1);
                        time = czas.GetCounter();
                    }
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                while (tablica.getSize() != 0) {
                    tablica.popFront();
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;



            case 4:
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);
                plikWyjsciowy <<endl<< "Pomiar usuwania z przodu:" << endl;

                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.pushFront(wartosc);
                }
                while (tablica.getSize() != 0) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    tablica.popFront();
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time<< endl;
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;



            case 5:
                plikWyjsciowy <<endl<< "Pomiar usuwania z tylu:" << endl;

                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.pushFront(wartosc);
                }
                while (tablica.getSize() != 0) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    tablica.popBack();
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;



            case 6:
                plikWyjsciowy <<endl<< "Pomiar usuwania w losowym miejscu:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.pushFront(wartosc);
                }
                while (tablica.getSize() != 0) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    tablica.popAny(rand() % tablica.getSize());
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;




            case 7:
                plikWyjsciowy <<endl<< "Pomiar sprawdzania czy wartość jest obecna:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.pushFront(wartosc);
                }

                for (int i = 0; i < tablica.getSize(); i++) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    tablica.checkIfPresent(rand() % 2000000 - 1000000);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }
                    while (tablica.getSize() != 0) {
                    tablica.popFront();
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;



            case 8:
                plikWyjsciowy <<endl<< "Pomiar wypisywania:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.pushFront(wartosc);
                }
                czas.StartCounter();
                tablica.print();
                time = czas.GetCounter();
                cout << "Czas wykonania: " << time << "ms" << endl;
                plikWyjsciowy  << time << "ms" << endl;

                while (tablica.getSize() != 0) {
                    tablica.popFront();
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;

        }

    }
}

void AutoTest::testListy() {
    srand(time(nullptr));
    Czas czas;
    Lista lista;
    int wybor = 99;
    int wartosc;
    int dataSize;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;
    double time;
    otworzPliki(plikWejsciowy, plikWyjsciowy, dataSize);
    sleep(1);
    system("CLS");

    while (wybor != 0) {
        cout << "Wybierz funkcje listy:" << endl;
        cout << "    1. Dodaj na poczatek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usun pierwszy" << endl;
        cout << "    5. Usun ostatni" << endl;
        cout << "    6. Usun ktorykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj listee" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        fflush(stdin);
        wybor = getch() - 48;

        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:

                plikWejsciowy.close();
                plikWyjsciowy.close();
                return;

            case 1:
                plikWyjsciowy <<endl<< "Pomiar dodawania z przodu:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    lista.pushFront(wartosc);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                while (lista.getSize() != 0) {
                    lista.popFront();
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 2:
                plikWyjsciowy <<endl<< "Pomiar dodawania z tylu:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    lista.pushBack(wartosc);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                while (lista.getSize() != 0) {
                    lista.popFront();
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 3:
                plikWyjsciowy <<endl<< "Pomiar dodawania na losowej pozycji:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;

                    if (lista.getSize() == 0) {
                        czas.StartCounter();
                        lista.pushAny(wartosc, 0);
                        time = czas.GetCounter();
                    } else {
                        czas.StartCounter();
                        lista.pushAny(wartosc, 1);
                        time = czas.GetCounter();
                    }
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                while (lista.getSize() != 0) {
                    lista.popFront();
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 4:
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);
                plikWyjsciowy <<endl<< "Pomiar usuwania z przodu:" << endl;
                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.pushFront(wartosc);
                }
                while (lista.getSize() != 0) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    lista.popFront();
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }


                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 5:
                plikWyjsciowy <<endl<< "Pomiar usuwania z tylu:" << endl;

                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);
                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.pushFront(wartosc);
                }
                while (lista.getSize() != 0) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    lista.popBack();
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 6:
                plikWyjsciowy <<endl<< "Pomiar usuwania w losowym miejscu:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);
                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.pushFront(wartosc);
                }
                while (lista.getSize() != 0) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    lista.popAny(rand() % lista.getSize());
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 7:
                plikWyjsciowy <<endl<< "Pomiar sprawdzania czy wartość jest obecna:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);
                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.pushFront(wartosc);
                }

                for (int i = 0; i < lista.getSize(); i++) {
                    //Wykonaj funkcje z pomiarem3
                    czas.StartCounter();
                    lista.checkIfPresent(rand() % 2000000 - 1000000);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                while (lista.getSize() != 0) {
                    lista.popFront();
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 8:
                plikWyjsciowy <<endl<< "Pomiar wypisywania:" << endl;
                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);
                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.pushFront(wartosc);
                }

                czas.StartCounter();
                lista.print();
                time = czas.GetCounter();
                cout << "Czas wykonania: " << time << "ms" << endl;
                plikWyjsciowy << time << "ms" << endl;

                while (lista.getSize() != 0) {
                    lista.popFront();
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;

        }

    }
}

void AutoTest::testKopca() {
    srand(time(nullptr));
    Czas czas;
    int wybor = 99;
    int wartosc;
    int dataSize;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;
    double time;

    otworzPliki(plikWejsciowy, plikWyjsciowy, dataSize);
    KopiecBinarny kopiec(dataSize);

    sleep(1);
    system("CLS");

    while (wybor != 0) {
        cout << "Wybierz funkcje Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usun" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        fflush(stdin);
        wybor = getch() - 48;

        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:

                plikWejsciowy.close();
                plikWyjsciowy.close();
                return;

            case 1:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    kopiec.push(wartosc);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }

                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;

            case 2:


                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    kopiec.pop(wartosc);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;

            case 3:
                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    kopiec.push(wartosc);
                }

                for (int i = 0; i < kopiec.getSize(); i++) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    kopiec.checkIfPresent(rand() % 2000000 - 1000000);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }
                cout << "Pomyslnie wykonano operacje [" << wybor << ']' << endl
                     << "Nacisnij downolny klawisz by kontynuowac..." << endl;
                getch();
                system("CLS");
                break;

            case 4:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    kopiec.push(wartosc);
                }

                czas.StartCounter();
                kopiec.print();
                time = czas.GetCounter();
                cout << "Czas wykonania: " << time << "ms" << endl;
                cout << "Pomyslnie wykonano operacje [" << wybor << ']' << endl
                     << "Nacisnij downolny klawisz by kontynuowac..." << endl;
                getch();
                system("CLS");
                break;
        }

    }
}

void AutoTest::testDrzewa() {
    srand(time(nullptr));
    Czas czas;
    int wybor = 99;
    int wartosc;
    int dataSize;
    double time;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    otworzPliki(plikWejsciowy, plikWyjsciowy, dataSize);
    Drzewo drzewo;

    sleep(1);
    system("CLS");


    while (wybor != 0) {
        cout << "Wybierz funkcje Drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usun" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        fflush(stdin);
        wybor = getch() - 48;

        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:

                plikWejsciowy.close();
                plikWyjsciowy.close();
                return;
            case 1:
                plikWyjsciowy <<endl<< "Pomiar dodawania:" << endl;

                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                while (plikWejsciowy.good()) {
                    //Wczytaj wartosc z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    drzewo.push(wartosc);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;

            case 2:
                plikWyjsciowy <<endl<< "Pomiar usuwania:" << endl;

                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    drzewo.push(wartosc);
                }


                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    drzewo.deleteElement(wartosc);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;

            case 3:

                plikWyjsciowy <<endl<< "Pomiar wyszukiwania" << endl;

                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                //Wypelnij tablice wartoscciami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    drzewo.push(wartosc);
                }

                for (int i = 0; i < drzewo.size; i++) {
                    //Wykonaj funkcje z pomiarem
                    czas.StartCounter();
                    drzewo.checkIfPresent(rand()% 2000000 - 1000000);
                    time = czas.GetCounter();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << time << endl;
                }
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;


            case 4:
                plikWyjsciowy <<endl<< "Pomiar dodawania z tyłu:" << endl;

                plikWejsciowy.clear();
                plikWejsciowy.seekg(0, ios::beg);

                czas.StartCounter();
                drzewo.printGraphic("", "", drzewo.root);
                time = czas.GetCounter();
                cout << "Czas wykonania: " << time << "ms" << endl;
                
                cout<<"Pomyslnie wykonano operacje ["<<wybor<<']'<<endl<<"Nacisnij downolny klawisz by kontynuowac..."<<endl;
                getch();
                system("CLS");
                break;

        }

    }
}