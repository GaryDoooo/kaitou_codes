#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
int main() {
    int n = read();
    int s[n], a[n];
    for (int i = 0; i < n; i++) s[i] = read();
    for (int i = 0; i < n; i++) a[i] = read();
    int p[n + 1], max_p = 0;
    for (int i = 0; i < n; i++) p[i] = (s[i] << 1) + a[i];
    p[n] = 0;
    for (int i = n - 1; i >= 0; i--) max_p = p[i] = max(max_p, p[i]);
    // priority_queue<int,vector<int>,less<int> > a;
    // for (int i = 0; i < n; i++) a.push(i);
    // while(!a.empty()){
    //     cout<<a.top()<<endl;
    //     a.pop();
    // }
    long long res[n];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++)
        if (p[i] > p[i + 1]) {
            sort(a, a + i);
            long long sum = p[i];
            res[0]        = max(res[0], sum);
            for (int j = i - 1; j >= 0; j--) {
                sum += a[j];
                res[i - j] = max(res[i - j], sum);
            }
        }
    for (int i = 0; i < n; i++) cout << res[i] << endl;
}
