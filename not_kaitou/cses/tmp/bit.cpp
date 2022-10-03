#include <bits/stdc++.h>
using namespace std;
void print(int x) {
    cout << x << ": " << '\t';
    for (int i = 31; i >= 0; i--) {
        cout << ((x >> i) & 1);
    }
    cout << endl;
}
int main() {
    for (int i = 10; i < 30; i++) {
        print(i);
        print(-i);
        print(i & -i);
    }
}

