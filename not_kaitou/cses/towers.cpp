#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int n, a;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        auto it = s.upper_bound(a);
        if (it != s.end()) s.erase(it);
        s.insert(a);
    }
    cout << s.size() << endl;
}
