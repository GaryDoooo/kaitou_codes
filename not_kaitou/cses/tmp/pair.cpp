#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void print(pii x) { cout << "(" << x.first << "," << x.second << ")" << endl; }
int main() {
    pii a, b, c;
    a = {1, 0};
    b = {2, 2};
    c = {2, 1};
    print(min(a, b));
    print(max(a, b));
    print(min(b, c));
    print(max(b, c));
    print(min(c, b));
    print(max(c, b));
    pii d[20];
    for (int i = 0; i < 20; i++) d[i] = {rand() % 20, rand() % 20};
    sort(d, d + 20);
    for (int i = 0; i < 20; i++) print(d[i]);
}

