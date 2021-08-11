#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int n = read(), result = 0;
    vector<int> scores{0, 101};
    for (int i = 0; i <	 n; i++) {
        int new_comer = read();
        // cout << new_comer;
        auto smaller = lower_bound(scores.begin(), scores.end(), new_comer);
        auto larger = upper_bound(scores.begin(), scores.end(), new_comer);
        // cout << smaller - scores.begin() + (*smaller < new_comer)  << " " << scores.end() - larger  << endl;
        // if (*smaller == new_comer and smaller > scores.begin()) smaller--;
        if (smaller - scores.begin() + (*smaller < new_comer) >= scores.end() - larger) result ++;
        scores.insert(smaller , new_comer);
        // for (auto j : scores) cout << j << " ";
        // cout << endl << result << " " << endl;
    }
    cout << result;
    return 0;
}