#include <iostream>
#include <vector>
using namespace std;
int main() {
    int x = 0;
    int c = 1;
    int pn = 0;
    vector<int> p = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    while (1) {
        int i = x % 10 + 1;
        if (p[i] != -1) {
            if (c == 3) {
                cout << i << " ";
                p[i] = -1;
                pn ++;
                c = 1;
            } else c ++;
        } x++;
        if (pn == 10) break;
    }
}