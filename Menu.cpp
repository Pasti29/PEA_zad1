#include "Menu.h"

int Menu::showMainMenu() {
    system("cls");
    int option;
    cout << "PEA - projekt nr 1" << endl;
    cout << "Autor: Karol Pastewski 252798" << endl << endl;
    cout << "Wpisz liczbe odpowiadajaca opcji z listy" << endl << endl;
    cout << "1.Poprawnosc implementacji" << endl;
    cout << "2.Pomiar czasu" << endl << endl;
    cout << "9.Wyjscie z programu" << endl;
    cin >> option;
    return option;
}

int Menu::showTestMenu() {
    system("cls");
    int option;
    cout << "Wpisz liczbe odpowiadajaca opcji z listy" << endl << endl;
    cout << "1.Wczytanie danych z pliku" << endl;
    cout << "2.Wygenerowanie danych z losowych" << endl;
    cout << "3.Wyswietlenie ostatnio wczytanych lub wygenerowanych danych" << endl;
    cout << "4.Algorytm przegladu zupelnego" << endl;
    cout << "5.Algorytm podzialu i ograniczen (B&B)" << endl << endl;
    cout << "8.Wstecz" << endl;
    cout << "9.Wyjscie z programu" << endl;
    cin >> option;
    return option;
}

int Menu::showTimeMenu() {
    system("cls");
    int option;
    cout << "Wpisz liczbe odpowiadajaca opcji z listy" << endl << endl;
    cout << "1.Algorytm przegladu zupelnego" << endl;
    cout << "2.Algorytm podzialu i ograniczen (B&B)" << endl << endl;
    cout << "8.Wstecz" << endl;
    cout << "9.Wyjscie z programu" << endl;
    cin >> option;
    return option;
}
