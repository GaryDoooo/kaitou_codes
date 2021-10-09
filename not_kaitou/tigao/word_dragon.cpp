#include <bits/stdc++.h>
using namespace std;
string s[20], start;
int done[20] = {0}, n, res = 0;
void dfs(string input, int start_pos) {
    // cout << input << endl;
    res = max(res, (int)input.length());
    for (int i = 0; i < n; i++) {
        if (done[i] >= 2) continue;
        for (int j = start_pos; j < input.length(); j++) {
            int len = input.length() - j;
            if (len >= s[i].length()) continue;
            if (input.substr(j, len) == s[i].substr(0, len)) {
                done[i]++;
                dfs(input + s[i].substr(len, s[i].length() - len), j + 1);
                done[i]--;
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> start;
    dfs(start, 0);
    cout << res;
}
