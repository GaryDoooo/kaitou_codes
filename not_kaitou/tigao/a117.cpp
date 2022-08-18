#include <bits/stdc++.h>
using namespace std;
unsigned long long fd[100005][35], fi[100005][35], fm[100005][35];
int n, K;
void print(int* a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) cout << *(a + i * 35 + j) << " ";
        cout << endl;
    }
    cout << endl;
}
int main() {
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++) scanf("%llu", &fi[i][0]);
    for (int i = 0; i < n; i++) scanf("%llu", &fd[i][0]);
    memcpy(fm, fd, sizeof(fm));
    for (int j = 1, k = 1; k <= 1e9; j++, k <<= 1)
        for (int i = 0; i < n; i++) {
            fi[i][j] = fi[fi[i][j - 1]][j - 1];
            fd[i][j] = fd[i][j - 1] + fd[fi[i][j - 1]][j - 1];
            fm[i][j] = min(fm[i][j - 1], fm[fi[i][j - 1]][j - 1]);
        }
    // print((int*)fi);
    // print((int*)fd);
    // print((int*)fm);
    for (int i = 0; i < n; i++) {
        unsigned long long temp = K, res_d = 0, idx = i, res_min = 2e9;
        for (int j = 0; j < 32 and temp > 0; j++, temp >>= 1) {
            if (temp & 1) {
                res_d += fd[idx][j];
                res_min = min(res_min, fm[idx][j]);
                idx     = fi[idx][j];
            }
        }
        printf("%llu %llu\n", res_d, res_min);
    }
}

