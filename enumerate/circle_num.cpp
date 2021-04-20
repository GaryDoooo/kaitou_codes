#include <iostream>
#include <vector>
using namespace std;
int main() {
    int x = 0;
    int c = 1;
    vector<int> p = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    while (1) {
        if (c == 3) {
            int i = x % 10 + 1;
            cout << i << " ";
            p[i] = -1;
            c == 1;
        } else c ++;
        x++;
    }
}