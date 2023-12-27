#include <iostream>
using namespace std;
int p[212345], n;
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) p[i] = i + 1;
    p[n]  = 1;
    int i = 1;
    while (p[i] != i) {
        int ii = i;
        i      = p[i];
        cout << i << " ";
        p[ii] = p[i];
        i     = p[i];
    }
    cout << i << endl;
}
