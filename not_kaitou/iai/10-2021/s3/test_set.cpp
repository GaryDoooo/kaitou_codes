#include <bits/stdc++.h>
using namespace std;
void print(set<int> &s) {
    for (int i : s) cout << i << " ";
    cout << endl;
}
int main() {
    set<int> s = {1, 2, 3, 4, 5, 6, 7};
    s.erase(2);
    print(s);
}

