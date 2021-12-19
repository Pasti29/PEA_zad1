#pragma once

#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

class BruteForce {
private:
    int **array;
    int N;
    int finalCost;
    int *finalPath;
    int *currentPath;

    static void swap(int &a, int &b);

    void permute(int left);

public:
    BruteForce(int **array, int N);

    ~BruteForce();

    void showResults();

    void findMinPath();
};
