#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }
    vector<int> res;
    for (int i = 1; i <= k; i++) {
        if (count(a.begin(), a.end(), i) == 2) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (auto i : res) {
        cout << i << " ";
    }
    // vector<int> b;
    // for (int i = 0; i < x.size() / 2; i++) {
    //     b.push_back(a.back());
    //     a.pop_back();
    // }
    // for (auto i : a) {
    //     if (cou)
    //     }
}