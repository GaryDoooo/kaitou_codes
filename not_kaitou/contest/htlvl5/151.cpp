#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int p[100000], n, ps[100000];
int main() {
    memset(p, 1, sizeof(p));
    for (int i = 3; i <= sqrt(1000); i += 2) {
        if (p[i])
            for (int j = i * i; j <= sqrt(100000); j += i) p[j] = 0;
    }
    ps[0]   = 2;
    int idx = 0, cnt = 0;
    cin >> n;
    for (int i = 3; i <= sqrt(n); i++)
        if (p[i]) ps[++idx] = i;
    for (int i = 0; i <= idx; i++) {
        if (n % ps[i] == 0) {
            int ys = n / ps[i];
            for (int j = 2; j <= sqrt(ys); j++) {
                if (ys % j == 0) {
                    cout << "It's not a Tongtong number." << endl;
                    return 0;
                }
            }
            cout << "It's a Tongtong number." << endl;
            return 0;
        }
    }
    cout << "It's not a Tongtong number." << endl;
}

