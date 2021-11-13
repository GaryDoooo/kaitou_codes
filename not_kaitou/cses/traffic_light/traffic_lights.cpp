#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
////////////////////////

int main() {
    int x = read(), n = read();
    set<int> q;
    multiset<int> gaps;
    q.insert(0);
    q.insert(x);
    gaps.insert(x);
    for (int i = 0; i < n; i++) {
        int a     = read();
        auto it   = q.upper_bound(a);
        int right = *(it--);
        int left  = *it;
        // cout << left << " " << right << endl;
        gaps.erase(gaps.find(right - left));
        gaps.insert(right - a);
        gaps.insert(a - left);
        q.insert(a);
        cout << *gaps.rbegin() << endl;
    }
}
