#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    cout << 50 << endl;
    cout << 10 << endl;
    for (int i = 0; i < 50; i++) {
        cout << rand() % 10 - 5 << " ";
    }
    for (int i = 0; i < 10; i++) {
        int end   = rand() % 49 + 2;
        int start = rand() % (end - 1) + 1;
        cout << start << " " << end << endl;
    }
}
