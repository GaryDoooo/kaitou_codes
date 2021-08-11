#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    unsigned long long spreader = 1, day1 = 0, day2 = 0;
    for (int i = 0; i < n; i++) {
        int new_day1 = spreader;
        int new_day2 = day1;
        int new_spreader = (spreader + day2) % 1000000007;
        day1 = new_day1;
        day2 = new_day2;
        spreader = new_spreader;
    }
    cout << (day1 + day2 + spreader) % 1000000007 << endl;
    return 0;
}