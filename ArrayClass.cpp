#include "ArrayClass.h"

// Funkcja ustawiająca wielkość tablicy wpisaną
// przez użytkownika
int ArrayClass::setN() {
    int N;
    cout << "Wpisz wielkosc tablicy (liczbe N): ";
    cin >> N;
    return N;
}

// Funkcja tworzy oraz zapełnia losowymi danymi
// tabelę, która jest macierzą sąsiedztwa
int **ArrayClass::createArray(int **array, int N) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 99);
    auto random = bind(distribution, gen);
    array = new int *[N];
    for (int i = 0; i < N; i++) {
        array[i] = new int[N];
        for (int j = 0; j < N; j++) {
            if (i == j) array[i][j] = -1;
            else {
                array[i][j] = random();
            }
        }
    }
    return array;
}

// Funkcja tworzy oraz wypełnia tabelę danymi z pliku
int **ArrayClass::createArrayFromFile(int **array, int &N) {
    string fileName;
    cout << "Podaj nazwe pliku (z rozszerzeniem): ";
    cin >> fileName;
    ifstream file(fileName);
    int var;
    if (file.is_open()) {
        file >> N;
        if (file.fail()) {
            cout << "Blad pliku - ODCZYT DLUGOSCI" << endl;
        } else {
            array = new int *[N];
            for (int i = 0; i < N; i++) {
                array[i] = new int[N];
                for (int j = 0; j < N; j++) {
                    file >> var;
                    if (i == j) {
                        array[i][j] = -1;
                    } else {
                        array[i][j] = var;
                    }

                    if (file.fail()) {
                        cout << "Blad pliku - ODCZYT TABLICY" << endl;
                        break;
                    }
                }
            }
        }

    }
    return array;
}

// Funkcja wyświetla macierz sąsiedztwa
void ArrayClass::showArray(int **array, int N) {
    cout << endl << "N = " << N << endl << endl;
    for (int i = 0; i < N; i++) cout << "-------";
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "|  " << left << setw(4) << array[i][j];
        }
        cout << "|" << endl;
        for (int j = 0; j < N; j++) cout << "-------";
        cout << endl;
    }
}

// Funkcja niszczy tabelę dynamiczną
int **ArrayClass::destroyArray(int **array, int N) {
    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }
    delete[] array;
    return nullptr;
}
