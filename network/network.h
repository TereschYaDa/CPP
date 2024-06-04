#pragma once
#include <iostream>
#include <string>
using namespace std;

class Network {
    int number;
    int** halts;
    string* names;
    
    void init() {
        halts = new int* [number];
        names = new string[number];

        for (int i = 0; i < number; i++) {
            halts[i] = new int[2];
            for (int j = 0; j < 2; j++) {
                halts[i][j] = 0;
            }
            names[i] = "halt #" + to_string(i + 1);
        }
    }
    
    void destroy() {
        int i = 0;
        while (i < number) {
            delete[] halts[i];
            halts[i] = nullptr;
            i++;
        }
        delete[] halts;
        halts = nullptr;
    }

public:
    Network() {
        number = 5;
        init();
    }
    
    Network(int n) {
        number = n;
        init();
    }

    void addHalts(int** a) {
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < a[i][0]; j++) {
                halts[i][j] = a[i][j];
            }
        }
    }
    
    void nullHalts() {
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < halts[i][0]; j++) {
                halts[i][j] = 0;
            }
        }
    }
    
    void autoAddHalts() {
        int i = 0;
        while (i < number) {
            delete[] halts[i];
            halts[i] = nullptr;
            i++;
        }
        i = 1;
        halts[0] = new int[3];
        halts[0][0] = 2;
        halts[0][1] = 1;
        halts[0][2] = number;
        while (i < number) {
            halts[i] = new int[3];
            halts[i][0] = 3;
            halts[i][1] = i - 1;
            halts[i][2] = i + 1;
            i++;
        }
        halts[number - 1] = new int[2];
        halts[number - 1][0] = 2;
        halts[number - 1][1] = 0;
    }
    
    void printHalts() {
        for (int i = 0; i < number; i++) {
            cout << names[i] << ": ";
            for (int j = 1; j < halts[i][0]; j++) {
                cout << halts[i][j] + 1 << ' ';
            }
            cout << endl;
        }
    }
    
    void printHalts(int i) {
        cout << names[i] << ": ";
        for (int j = 1; j < halts[i][0]; j++) {
            cout << halts[i][j] << ' ';
        }
        cout << endl;
    }
    
    void printHalts(int i, string s) {
        if (s == "name")
            cout << names[i];
    }
    
    void rename(int n, string s) { names[n] = s; }
    
    void addHalt(int n, int* a) {
        for (int i = 0; i < halts[i][0]; i++)
            halts[n][i] = a[i];
    }
   
    void addHalt(int n) {
        int in;
        cout << "Add halts by " << names[n] << endl;
        for (int i = 0; i < halts[i][0]; i++) {
        step:
            cin >> in;
            if (in - 1 >= number) {
                cout << "Wrong input: there ain't " << in << "th halt. Add again"
                    << endl;
                goto step;
            }
            if (in - 1 == n) {
                cout << "Wrong input: its next halt can't be itself. Add again" << endl;
                goto step;
            }
            halts[n][i] = in;
        }
    }

    bool isThereRoute(int a, int b) {
        int i = 0;
        bool br = false;
        while (i < halts[a][0]) {
            if (halts[a][i] == b) {
                br = true;
                break;
            }
            i++;
        }
        return br;
    }
   
    bool isThereWay(int a, int b) {
        int i = 0;
        bool br = false;

        while (i < halts[a][0]) {
            if (halts[a][i] == b) {
                br = true;
                break;
            }
            i++;
        }

        i = 0;

        if (!br) {
            while (i < halts[a][0]) {
                if (isThereWay(halts[a][i], b)) {
                    br = true;
                    break;
                }
                i++;
            }
        }
        return br;
    }
    
    bool isThereRoute(int a, int b, int count) {
        int i = 0, c = 1;
        bool br = false;
        while (i < halts[a][0]) {
            if ((halts[a][i] == b) and (1 == count)) {
                br = true;
                break;
            }
            i++;
        }
        i = 0;
        if (!br) {
            while (i < halts[a][0]) {
                c++;
                if (isThereRoute(halts[a][i], b, count - 1) and (c == count)) {
                    br = true;
                    break;
                }
                i++;
            }
            return br;
        }
    }
};