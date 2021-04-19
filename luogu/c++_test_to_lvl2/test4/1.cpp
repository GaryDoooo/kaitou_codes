#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &v) {
    for (auto i : v) cout << i << " ";
    cout << endl;
}

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
    vector<int> f(t.begin(), t.end() - mid);
    print_vector(f);
    vector<int> b(t.begin() + mid, t.end());
    reverse(b.begin(), b.end());
    print_vector(b);
    for (int i = 0; i < f.size(); i++) {
        if (f[i] + b[i] > max) max = f[i] + b[i];
    }
    cout << max;
    return 0;
}
