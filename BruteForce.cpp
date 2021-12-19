#include "BruteForce.h"

// Konstruktor inicjalizujący wszystkie potrzebne zmienne
BruteForce::BruteForce(int **array, int N) {
    this->array = array;
    this->N = N;
    finalCost = INT_MAX;
    finalPath = new int[N + 1];
    currentPath = new int[N + 1];
}

// Dekonstruktor niszczący, używane przez algorytm, tablice
// dynamiczne
BruteForce::~BruteForce() {
    delete[] currentPath;
    delete[] finalPath;
}

// Wyświetlenie wyników działania algorytmu
void BruteForce::showResults() {
    cout << "Min Path Brute Force = " << finalCost << endl;
    for (int i = 0; i < N + 1; i++) {
        cout << finalPath[i] << " ";
    }
    cout << endl << endl;
}

// Funkcja zamienia miejscami dwie liczby
void BruteForce::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Funkcja rekurencyjna tworząca wszystkie permutacje ścieżki
// oraz sprawdzająca, czy aktualna ścieżka jest lepsza od tej
// końcowej.
// left - indeks, od którego ma się zacząć permutacja
void BruteForce::permute(int left) {
    if (left == N - 1) {

        int currentCost = 0;
        for (int i = 0; i < N; i++) {
            currentCost += array[currentPath[i]][currentPath[i + 1]];
        }
        if (currentCost < finalCost) {
            finalCost = currentCost;
            memcpy(finalPath, currentPath, (N + 1) * sizeof(int));
        }
    } else {
        for (int i = left; i < N; i++) {
            swap(currentPath[left], currentPath[i]);
            permute(left + 1);
            swap(currentPath[left], currentPath[i]);
        }
    }
}

// Funkcja ustawiające początkowe wartości dla tablic
// oraz wywołuje funkcję rekurencyjną permute
void BruteForce::findMinPath() {
    for (int i = 0; i < N + 1; i++) {
        currentPath[i] = i;
    }
    currentPath[0] = 0;
    currentPath[N] = 0;
    permute(1);
}

