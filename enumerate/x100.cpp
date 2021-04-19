#include <iostream>
using namespace std;
int main() {
    int x = 3;
    while (x < 100) {
        if (x % 2 == 0) x += 3;
        else x *= 2;
    }
    cout << x << endl;
}