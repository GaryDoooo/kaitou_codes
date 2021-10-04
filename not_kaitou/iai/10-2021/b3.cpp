#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    long long s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    s = s >> 1;
    for (int i = 0; i < n; i++) {
        if (a[i] >= s) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << endl;
}
