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
    for (int i : vi) {
        for (int j : vi) {
            // cout << i << " " << j << endl;
            if (find(vi.begin(), vi.end(), i - j) != vi.end() and i - j != j and i - j != i) {
                res ++;
                // cout << "found" << endl;
                break;
            }
        }
    }
    cout << res << endl;
}