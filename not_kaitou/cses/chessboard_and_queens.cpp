#include <bits/stdc++.h>
using namespace std;
int reserved[8][8], res, place[8];
void dfs(int y) {
    if (y >= 8) {res++; return;}
    for (int x = 0; x < 8; x++) {
        if (reserved[y][x]) continue;
        bool safe = true;
        for (int i = 0; i < y; i++) {
            if (place[i] == x) safe = false;
            if (y - i == x - place[i]) safe = false;
            if (i - y == x - place[i]) safe = false;
        }
        if (safe) {
            place[y] = x;
            dfs(y + 1);
        }
    }
}
int main() {
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            char c = s[j];
            if (c == '*') reserved[i][j] = 1;
        }
    }
    dfs(0);
    cout << res;
}
