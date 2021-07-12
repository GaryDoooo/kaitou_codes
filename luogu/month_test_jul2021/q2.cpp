#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> scores = {};
    int x;
    while (cin >> x) {
        scores.push_back(x);
    }
    sort(scores.begin(), scores.end());
    int e = 0;
    for (int i = 0; i < 3; i++) {
        e += scores.pop_back();
    }
    cout << e;
    return 0;
}