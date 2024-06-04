#pragma once
#include <fstream>
#include <iostream>
using namespace std;

#define BUFFER_SIZE 100

int PlotsField(char net[][BUFFER_SIZE], int rows, int cols, int i, int j) {
    if (net[i][j] != '#') {
        return 0;
    }

    net[i][j] = '.';

    PlotsField(net, rows, cols, i + 1, j);
    PlotsField(net, rows, cols, i - 1, j);
    PlotsField(net, rows, cols, i, j + 1);
    PlotsField(net, rows, cols, i, j - 1);

    return 1;
}
