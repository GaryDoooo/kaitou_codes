#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> vi;
    int temp;
    while (cin >> temp) vi.push_back(temp);
////////////////////////////////
    int res = 0;
    sort(vi.begin(), vi.end());
    for (auto i = vi.begin(); i != vi.end(); i++) {
        for (auto j = vi.begin(); *j <= (*i) / 2 ; j++) {
            auto t = lower_bound(j, i, *i - *j);
            // cout << *i << "lower " << *j << " " << *t << endl;
            if (*t + *j == *i and t != j) {
                // cout << *i << " " << *j << " " << *t << endl;
                res++;
                break;
            }
        }
    }
    cout << res << endl;
}