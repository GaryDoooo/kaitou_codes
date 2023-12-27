#include <bits/stdc++.h>
using namespace std;

void test_ordered_map() {
    map<int, int> m;
    m[3] = 30;
    m[1] = 10;
    m[2] = 20;
    m[4] = 40;
    for (auto i : m) {
        cout << i.second << endl;
    }
}

void test_unordered_map() {
    unordered_map<int, int> m;
    m[3] = 30;
    m[1] = 10;
    m[2] = 20;
    m[4] = 40;
    for (auto i : m) {
        cout << i.second << endl;
    }
}

int main() {
    test_ordered_map();
    test_unordered_map();
}
