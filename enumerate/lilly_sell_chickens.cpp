#include <iostream>
using namespace std;
int main() {
    for (int i = 1; i < 12; i++) {
        int morning = i * 7;
        for (int m = 1; m < 7; m++) {
            if (morning + (24 - i)*m == 132) cout << i;
        }
    }
}