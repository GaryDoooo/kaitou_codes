#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int cnt    = 0;
    double res = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i], c2 = '`';
        if (c == '+' || c == '-') continue;
        if (i + 1 < s.size()) c2 = s[i + 1];
        double score;
        if (c == 'A') score = 4;
        if (c == 'B') score = 3;
        if (c == 'C') score = 2;
        if (c == 'D') score = 1;
        if (c2 == '+') score += 0.3;
        if (c2 == '-') score -= 0.3;
        cnt++;
        res += score;
        // cout << score << " " << cnt << c << c2 << endl;
    }
    printf("%.2f\n", res / cnt);
}

