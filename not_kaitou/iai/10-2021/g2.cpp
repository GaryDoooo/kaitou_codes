#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
int target[11], target_len = 0, first_occurrence[200];
int a[100] = {0};
int d[8]   = {1, -1, 10, -10, 9, 11, -9, -11};
ull count(int start, int pos) {
    if (pos >= target_len) return 1;
    ull res  = 0;
    a[start] = 0;
    for (int i = 0; i < 8; i++) {
        int next = start + d[i];
        if (a[next] == target[pos + 1]) res += count(next, pos + 1);
    }
    a[start] = target[pos];
    return res;
}
int main() {
    string input;
    cin >> input;
    for (int i = 0; i <= (target_len = input.length() - 1); i++) {
        target[i] = (int)input[i];
    }
    for (int y = 1; y <= 8; y++) {
        cin >> input;
        for (int x = 1; x <= 8; x++) a[(y * 10) + x] = (int)input[x - 1];
    }
    ull res = 0;
    for (int i = 0; i < 100; i++)
        if (a[i] == target[i]) res += count(i, 0);

    // for (int y = 1; y < 5; y++) {
    //     for (int x = 1; x <= 4; x++) {
    //         int i = y * 10 + x;
    //         if (a[i] == target[0]) {
    //             res += count(i, 0);
    //         }
    //     }
    // }
    cout << res;
}
