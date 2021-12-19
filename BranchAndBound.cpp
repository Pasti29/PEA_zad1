#include "BranchAndBound.h"

// Konstruktor inicjalizujący wszystkie potrzebne zmienne
BranchAndBound::BranchAndBound(int **array, int N) {
    this->array = array;
    this->N = N;
    visited = new bool[N];
    finalPath = new int[N + 1];
    currentPath = new int[N];
    finalCost = INT_MAX;
}

// Dekonstruktor niszczący, używane przez algorytm, tablice
// dynamiczne
BranchAndBound::~BranchAndBound() {
    delete[] visited;
    delete[] finalPath;
    delete[] currentPath;
}

// Funkcja znajdująca koszt do najbliższego sąsiada
int BranchAndBound::findNearest(int i) {
    int min = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (array[i][j] < min && i != j) {
            min = array[i][j];
        }
    }
    return min;
}

// Funkcja rekurencyjna
// currentCost - obecny koszt rozpatrywanej ścieżki
// level - poziom drzewa, zaczynamy od 1, aż do N
// lowerBound - dolne ograniczenie dla rozpatrywanej ścieżki
void BranchAndBound::recursion(int currentCost, int level, int lowerBound) {
    // Jeżeli jesteśmy na ostatnim poziomie drzewa, to sprawdzane jest, czy
    // rozpatrywana ścieżki jest krótsza od najkrótszej dotąd znalezionej
    // ścieżki
    if (level == N) {
        currentCost += array[currentPath[level - 1]][0];
        if (currentCost < finalCost) {
            for (int i = 0; i < N; i++) {
                finalPath[i] = currentPath[i];
            }
            finalPath[N] = 0;
            finalCost = currentCost;
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (array[currentPath[level - 1]][i] != -1 && !visited[i]) {
                int tmpLowerBound = lowerBound;
                int tmpCurrentCost = currentCost;

                currentCost += array[currentPath[level - 1]][i];
                lowerBound -= findNearest(currentPath[level - 1]);

                // lowerBound + currentCost to jest nasze dolne ograniczenie, jeżeli
                // jest mniejsze od finalCost, to możliwe jest znalezienie lepszej ścieżki,
                // więc ścieżka do rozpatrywanego punktu jest dalej rozwijana
                if (lowerBound + currentCost < finalCost) {
                    currentPath[level] = i;
                    visited[i] = true;
                    recursion(currentCost, level + 1, lowerBound);
                }

                // Jeżeli dolne ograniczenie wyeliminowało nam rozpatrywany punkt albo chcemy przejść do następnego
                // nierozpatrzonego punktu (czyli kolejny punkt na "stosie"), to resetowane są wszystkie zmiany
                lowerBound = tmpLowerBound;
                currentCost = tmpCurrentCost;
                memset(visited, false, N * sizeof(bool));
                for (int j = 0; j < level; j++) {
                    visited[currentPath[j]] = true;
                }
            }
        }
    }
}

// Wyświetlenie wyników działania algorytmu
void BranchAndBound::showResult() {
    cout << "Min Path BranchAndBound = " << finalCost << endl;
    for (int i = 0; i < N + 1; i++) {
        cout << finalPath[i] << " ";
    }
    cout << endl << endl;
}

// Funkcja ustawiające początkowe wartości dla tablic
// oraz wywołuje funkcję rekurencyjną recursion
void BranchAndBound::findMinPath() {

    // Tablica currentPath przechowywuje obecnie rozpatrywaną ścieżkę
    memset(currentPath, -1, N * sizeof(int));
    currentPath[0] = 0;

    // Tablica visited sprawdza, czy byliśmy już w danym punkcie, czy nie
    memset(visited, false, N * sizeof(bool));
    visited[0] = true;

    // lowerBound - dolne ograniczenie, obliczane wyszukując dla każdego
    // punktu koszt do najbliższego sąsiada i sumujący te wartości
    int lowerBound = 0;
    for (int i = 0; i < N; i++) {
        lowerBound += findNearest(i);
    }

    recursion(0, 1, lowerBound);
}
