#pragma once

#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

class BranchAndBound {
private:
    int **array;
    int N;
    bool *visited;
    int *finalPath;
    int *currentPath;
    int finalCost;

    int findNearest(int i);

    void recursion(int currentCost, int level, int lowerBound);

public:
    BranchAndBound(int **array, int N);

    ~BranchAndBound();

    void showResult();

    void findMinPath();
};
