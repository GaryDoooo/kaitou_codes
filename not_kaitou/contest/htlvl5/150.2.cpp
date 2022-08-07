#include <iostream>
using namespace std;
int main() {
    for (int i = 1; i <= 100000; i++) {
        int s = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) s += j;
        }
        if (s == i) cout << i << endl;
    }
}
