#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    cout << 100000 << endl;
    for (int i = 0; i < 100000; i++) {
        cout << rand() % int(1e9) << endl;
    }
    cout << 10000 << endl;
    for (int i = 0; i < 10000; i++) {
        int end   = rand() % 99990 + 11;
        int start = rand() % end + 1;
        cout << start << " " << end << endl;
    }
}
