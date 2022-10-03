#include <iostream>
using namespace std;
int main() {
    int cnt = 0, a[20], b;
    for (int i = 0; i < 10; i++) cin >> a[i];
    cin >> b;
    for (int i = 0; i < 10; i++) cnt += (b >= a[i]);
    cout << cnt;
}
