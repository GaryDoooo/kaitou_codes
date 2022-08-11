#include <bits/stdc++.h>
using namespace std;
int const MOD = 1000000007;
int n, m, k, a[1005], b[205], res;
int f[1005][205];  // end at a[i] and b[i] substring res;
int s[1005][205][205];
vector<int> o[26];  // occurance position
char input[1005];
// struct node{
//     int cnt,ap,bp;
// };
// queue<node> q;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s\n", input);
    for (int i = 0; i < n; i++) {
        char c = input[i];
        a[i]   = c - 'a';
        o[a[i]].push_back(i);
    }
    scanf("%s\n", input);
    for (int i = 0; i < m; i++) {
        char c = input[i];
        b[i]   = c - 'a';
    }
    int last_occurrence = -1;
    for (int start = 0; start < m; start++) {
        int cnt[m], this_occurrence = 1e9;
        memset(cnt, 0, sizeof(cnt));
        for (int a_pos : o[b[start]]) {
            if (n - a_pos < m - start or a_pos <= last_occurrence) continue;
            this_occurrence        = min(this_occurrence, a_pos);
            s[a_pos][start][start] = ++cnt[start];
            for (int end = start + 1; end < m; end++) {
                if (a[a_pos + end - start] == b[end])
                    s[a_pos][start][end] = ++cnt[end];
                else
                    break;
            }
        }
        last_occurrence = this_occurrence;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) cout << s[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }
    for (int cut=0;cut<k; cut++){
        if (cut<k-1){
        for (int p=0; p<m; p++){

            
}

