#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &v) {
    for (auto i : v) cout << i << " ";
    cout << endl;
}
int main() {
    vector<int> v{1};
    make_heap(v.begin(), v.end());
    v.push_back(3);
    print(v);
    push_heap(v.begin(), v.end());
    print(v);
    v.push_back(2);
    print(v);
    push_heap(v.begin(), v.end());
    print(v);
    v.push_back(20);
    print(v);
    push_heap(v.begin(), v.end());
    print(v);
}

