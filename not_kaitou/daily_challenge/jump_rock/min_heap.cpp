#include <bits/stdc++.h>
using namespace std;
struct gap {
    int index, gap;
};
struct CompareLength {
    bool operator()(gap const &a, gap const &b) {
        return a.gap > b.gap;
    }
};
// bool cmp
int main() {
    priority_queue<gap, vector<gap>, CompareLength> queue;
    gap a;
    a.index = 1; a.gap = 2;
    queue.push(a);
    a.index = 2; a.gap = 3;
    queue.push(a);
    a.index = 3; a.gap = 0;
    queue.push(a);
    while (!queue.empty()) {
        cout << queue.top().gap << endl;
        queue.pop();
    }
}