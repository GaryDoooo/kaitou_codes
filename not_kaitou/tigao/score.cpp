#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[100];
    int f = 0, a = 0;
    do {
        // cin >> input;
        // s = input;
        scanf("%s", s);
        for (int left = 0; s[left] != '\0'; left++) {
            if (s[left] == 'E') {
                if (a + f > 0) printf("%d:%d\n", f, a);
                return 0;
                // cout << f << ":" << a << endl;
            }
            if (s[left] == 'F') f++;
            if (s[left] == 'A') a++;
            if (abs(f - a) > 1 and (a >= 11 or f >= 11)) {
                // cout << f << ":" << a << endl;
                printf("%d:%d\n", f, a);
                f = a = 0;
            }
        }
    } while (1);
}
