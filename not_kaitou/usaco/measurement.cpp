#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    int a, b;
    string s;
    map<string, int> m = {{"Mildred", 1}, {"Bessie", 0}, {"Elsie", 2}};
    int res = -1, oldres = 7, cnt = 0;
    int changes[101][3];
    memset(changes, 0, sizeof(changes));
    int current[3] = {0};
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a >> s >> b;
        changes[a][m[s]] = b;
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j < 3; j++) current[j] += changes[i][j];
        int maxres = max(max(current[0], current[1]), current[2]);
        res        = (current[0] == maxres) + (current[1] == maxres) * 2 +
              (current[2] == maxres) * 4;
        if (res != oldres) {
            cnt++;
            oldres = res;
        }
    }
    fout << cnt;
}
