#include <bits/stdc++.h>
using namespace std;
map<char, int> c2i;
int m[55][55], n, done[55], dist;
string inp1, inp2;
struct node {
    int dist, end;
};
bool operator<(const node& a, const node& b) { return a.dist < b.dist; }
multiset<node> q;
int main() {
    cin >> n;
    memset(m, 127, sizeof(m));
    // cout << m[0][0] << endl;
    int j = 0;
    for (char i = 'A'; i <= 'Z'; i++, j++) c2i[i] = j;
    j = 26;
    for (char i = 'a'; i <= 'z'; i++, j++) c2i[i] = j;
    // cout << c2i['a'] << endl;
    for (int i = 0; i < n; i++) {
        cin >> inp1 >> inp2 >> dist;
        int n1 = c2i[inp1[0]], n2 = c2i[inp2[0]];
        // cout << n1 << " " << n2 << " " << dist << endl;
        // string subs = inp.substr(4);
        // cout << subs << endl;
        // int dist  = stoi(subs);
        m[n1][n2] = min(m[n1][n2], dist);
        m[n2][n1] = min(m[n2][n1], dist);
    }
    // node n1 = {1, 2}, n2 = {2, 3};
    // if (n1 < n2)
    //     puts("true");
    // else
    //     puts("false");
    // for (int i = 0; i < 52; i++) {
    //     cout << m[25][i] << " ";
    // }
    // cout << endl;
    q.insert({0, 25});
    cout << q.size();
    while (!q.empty()) {
        node now = *q.begin();
        // cout << q.size() << " " << now.dist << " " << now.end << endl;
        done[now.end] = 1;
        q.erase(q.begin());
        // cout << q.size() << endl;
        if (now.end < 25) {
            cout << char('A' + now.end) << " " << now.dist << endl;
            return 0;
        }
        for (int next = 0; next < 52; next++) {
            if (done[next] or m[now.end][next] > 2e9) continue;
            q.insert({m[now.end][next] + now.dist, next});
        }
    }
    cout << "no found" << endl;
}
