#include <bits/stdc++.h>
using namespace std;
set<string> s;
int used[10];
string inp, res;
void dfs(string p) {
    if (p.length() == inp.length()) {
        s.insert(p);
        return;
    }
    for (int i = 0; i < inp.length(); i++) {
        if (used[i]) continue;
        used[i] = true;
        // res=res+inp[i];
        dfs(p + inp[i]);
        used[i] = false;
    }
}
int main() {
    cin >> inp;
    res = "";
    dfs(res);
    printf("%d\n", s.size());
    for (auto i : s) printf("%s\n", i.c_str());
}
