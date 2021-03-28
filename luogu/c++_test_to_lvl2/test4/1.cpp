#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t;
    int temp;
    while (cin >> temp) t.push_back(temp);
////////////////////////////////
    sort(t.begin(), t.end());
    // cout << t[0] + t.back();
    int mid = t.size() / 2;
    int max = 0;
    vector<int> f (t.begin(), t.end() - mid);
    vector<int> b (t.begin() + mid, t.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < f.size() - 1; i++) {
        if (f[i] + b[i] > max) max = f[i] + b[i];
    }
    cout << max;
    return 0;
}
