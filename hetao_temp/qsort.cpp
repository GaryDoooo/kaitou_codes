#include <iostream>
using namespace std;
int n, a[1000001];
void qsort(int l, int r) {
    cout << l << " " << r << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    if (l >= r) return;
    int p = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < p) {
            i++;
        }
        while (a[j] > p) {
            j--;
        }
        if (i <= j) {
            swap(a[j], a[i]);
            i++;
            j--;
        }
    }
    cout << i << " " << j << endl;
    if (l < j) {
        qsort(l, j);
    }
    if (i < r) {
        qsort(i, r);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    qsort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}