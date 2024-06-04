#include <iostream>
#include "Network.h"

int main() {
    int n = 5;
    int* arr = new int[4]; 
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;

    Network net(n);
    net.autoAddHalts();
    net.addHalt(4, arr);

    net.rename(0, "school");
    net.rename(1, "univer");
    net.rename(2, "shop");
    net.rename(3, "workshop");
    net.rename(4, "airport"); 

    int a = 0, b = 4;
    net.printHalts();

    if (net.isThereRoute(a, b, 1)) {
        cout << "We can go from ";
        net.printHalts(a, "name");
        cout << " to ";
        net.printHalts(b, "name");
    } else {
        cout << "We can't go from ";
        net.printHalts(a, "name");
        cout << " to ";
        net.printHalts(b, "name");
    }

    return 0;
}
