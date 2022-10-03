#include <bits/stdc++.h>
using namespace std;
inline long long read() {
    long long x = 0;  //, f = 1;
    char ch     = getchar();
    while (!isdigit(ch)) {
        ch = getchar();
    }
    while (isdigit(ch)) {
        x  = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;  // * f;
}
int n, k, res = 0;
struct number {
    int two, five;
};
int main() {
    n = read(), k = read();
    number a[n];
    int total_five = 0;
    for (int i = 0; i < n; i++) {
        long long a_in = read();
        int t = 0, f = 0;
        while (a_in % 2 == 0) {
            t++;
            a_in /= 2;
        }
        while (a_in % 5 == 0) {
            f++;
            a_in /= 5;
        }
        total_five += (a[i].five = f);
        a[i].two = t;
    }
    int v[k + 1][total_five + 1];
    memset(v, 255, sizeof(v));
    v[0][0] = 0;
    // for (int i = 1; i <= total_five; i++) v[0][i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = total_five; j >= 0; j--) {
            // v's 2nd index is how many five added, value is how many two it
            // has V's 1st index is how many numbers used
            int left_point = j - a[i].five;
            if (left_point < 0) break;
            for (int l = min(i, k - 1); l >= 0; l--)
                if (v[l][left_point] >= 0)
                    v[l + 1][j] = max(v[l][left_point] + a[i].two, v[l + 1][j]);
        }
        // for (int l = 0; l <= total_five; l++) {
        // for (int j = 0; j <= min(i + 1, k); j++) cout << v[j][l] << " ";
        // cout << endl << endl;
        // }
    }
    int res = 0;
    for (int i = 0; i <= total_five; i++) {
        res = max(res, min(i, v[k][i]));
        // for (int j = 0; j <= k; j++) cout << v[j][i] << " ";
        // cout << endl;
    }
    cout << res;
}

