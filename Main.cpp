#include "Menu.h"
#include "ArrayClass.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
#include <windows.h>

int **ARRAY = nullptr;
int N;

long long int read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int) count.QuadPart);
}

void test(int option) {
    if (option == 1) {
        if (ARRAY != nullptr) {
            ARRAY = ArrayClass::destroyArray(ARRAY, N);
        }
        ARRAY = ArrayClass::createArrayFromFile(ARRAY, N);
    } else if (option == 2) {
        if (ARRAY != nullptr) {
            ARRAY = ArrayClass::destroyArray(ARRAY, N);
        }
        N = ArrayClass::setN();
        ARRAY = ArrayClass::createArray(ARRAY, N);
    } else if (option == 3) {
        if (ARRAY == nullptr) {
            cout << "Niezainicjalozowano tabeli." << endl;
        } else {
            ArrayClass::showArray(ARRAY, N);
        }
    } else if (option == 4) {
        if (ARRAY == nullptr) {
            cout << "Niezainicjalozowano tabeli." << endl;
        } else {
            BruteForce BF(ARRAY, N);
            BF.findMinPath();
            BF.showResults();
        }

    } else if (option == 5) {
        if (ARRAY == nullptr) {
            cout << "Niezainicjalozowano tabeli." << endl;
        } else {
            BranchAndBound BnB(ARRAY, N);
            BnB.findMinPath();
            BnB.showResult();
        }
    }
}

void measureTime(int option) {
    N = ArrayClass::setN();
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    long long int average = 0;
    for (int i = 0; i < 100; i++) {
        ARRAY = ArrayClass::createArray(ARRAY, N);

        if (option == 1) {
            BruteForce BF(ARRAY, N);
            start = read_QPC();
            BF.findMinPath();
            elapsed = read_QPC() - start;
        } else if (option == 2) {
            BranchAndBound BnB(ARRAY, N);
            start = read_QPC();
            BnB.findMinPath();
            elapsed = read_QPC() - start;
        }
        average += elapsed;
        cout << "Time [us] = " << (1000000 * elapsed) / frequency << endl;
        ARRAY = ArrayClass::destroyArray(ARRAY, N);
    }
    cout << "Average time [us] = " << (1000000 * (average / 100)) / frequency << endl;
}

int main() {
    int option;

    while (true) {
        option = Menu::showMainMenu();
        if (option == 9) {
            system("pause");
            return 0;
        } else if (option == 1) {
            while (true) {
                option = Menu::showTestMenu();
                if (option == 8) {
                    if (ARRAY != nullptr) {
                        ARRAY = ArrayClass::destroyArray(ARRAY, N);
                    }
                    break;
                } else if (option == 9) {
                    if (ARRAY != nullptr) {
                        ARRAY = ArrayClass::destroyArray(ARRAY, N);
                    }
                    system("pause");
                    return 0;
                } else test(option);
                system("pause");
            }
        } else if (option == 2) {
            while (true) {
                option = Menu::showTimeMenu();
                if (option == 8) break;
                else if (option == 9) {
                    system("pause");
                    return 0;
                } else measureTime(option);
                system("pause");
            }
        }
    }
}
