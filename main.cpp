#include <iostream>
#include <conio.h>
#include "Test.h"
#include "AutoTest.h"

using namespace std;

int main() {
    //Inicjalizacja klasy testujacej
    Test test;
    int wybor = 99;
    int mode;

    cout << "SDiZO, Projekt 1, Maciej Ciura, 248879" << endl << endl;

    //Poczatkowe menu wyboru
    while (wybor) {
        system("CLS");
        cout << "Wybierz test:" << endl;
        cout << "  [1] Tablica Dynamiczna" << endl;
        cout << "  [2] Lista" << endl;
        cout << "  [3] Kopiec Binarny" << endl;
        cout << "  [4] Drzewo Czerowno-Czarne" << endl;
        cout << "  [0] Wyjscie" << endl << endl;
        fflush(stdin);
        wybor = getch() - 48;

        if (wybor == 0) return 0;

        system("CLS");
        cout << "Wybierz tryb pracy: " << endl;
        cout << "  [1] Manualny - Sprawdz funkcjonalnosci struktur." << endl;
        cout << "  [2] Automatyczny - Dane zostana pobrane z pliku, a pomiar czasu zapisany w pliku wynikowym." << endl;
        cout << "  [0] Powrot";
        fflush(stdin);
        mode = getch() - 48;
        system("CLS");

        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 1:
                cout << "[Test tablicy dynamicznej]" << endl << endl;
                if (mode == 0) break;
                if (mode == 2) AutoTest::testTablicy();
                else test.testTablicy();

                break;

            case 2:
                cout << "[Test listy]" << endl << endl;
                if (mode == 0) break;
                if (mode == 2) AutoTest::testListy();
                else test.testListy();
                break;

            case 3:
                cout << "[Test kopca binarnego]" << endl << endl;
                if (mode == 0) break;
                if (mode == 2) AutoTest::testKopca();
                else test.testKopca();
                break;

            case 4:
                cout << "[Test drzewa]" << endl << endl;
                if (mode == 0) break;
                if (mode == 2) AutoTest::testDrzewa();
                else test.testDrzewa();
                break;

        }
    }
}
