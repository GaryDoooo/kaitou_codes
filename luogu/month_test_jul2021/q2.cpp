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
    //for (auto i : scores) cout << i << " ";
    for (int i = 0; i < 3; i++) {
        //cout << scores.back() << " " << e << endl;
        e += scores.back();
        scores.pop_back();
    }
    cout << e;
    return 0;
}