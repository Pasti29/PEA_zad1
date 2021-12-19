#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <functional>

using namespace std;

class ArrayClass {

public:

    static int setN();

    static int **destroyArray(int **array, int N);

    static int **createArray(int **array, int N);

    static int **createArrayFromFile(int **array, int &N);

    static void showArray(int **array, int N);

};
