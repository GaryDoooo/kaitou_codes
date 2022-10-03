#include <iostream>
using namespace std;
int main() {
    int water = 100;
    int water_loss = 3;
    int x = 0;
    while (1) {
        if (x == 2) water_loss = 8;
        water -= water_loss;
        if (x == 4) break;
        x += 1;
    }
    cout << water;
}