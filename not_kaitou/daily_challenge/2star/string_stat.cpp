#include <bits/stdc++.h>
using namespace std;
int main() {
    char c;
    int lower = 0, upper = 0, num = 0;
    while (true) {
        c = getchar();
        if (c == '#') {
            cout << upper << " " << lower << " " << num << endl;
            return 0;
        }
        lower += islower(c) > 0;
        upper += isupper(c) > 0;
        num += isdigit(c) > 0;
    }
}
