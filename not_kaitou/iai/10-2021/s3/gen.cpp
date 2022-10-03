#include <bits/stdc++.h>
using namespace std;
int randint(int base) { return rand() % base; }
int main() {
    srand(time(NULL));
    cout << 200000 << " ";
    cout << randint(1e9) << " ";
    for (int i = 0; i < 200000; i++) cout << randint(1e9) << " ";
}
