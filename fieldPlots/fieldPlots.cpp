#include "fieldPlots.h"

int main() {
    ifstream inputFile("input.txt");

    int rows, cols;
    inputFile >> rows >> cols;

    char net[BUFFER_SIZE][BUFFER_SIZE];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputFile >> net[i][j];
        }
    }

    inputFile.close();

    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (net[i][j] == '#') {
                count += PlotsField(net, rows, cols, i, j);
            }
        }
    }

    cout << count << endl;

    return 0;
}
