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
    int color_count[1000001] = {0};
    // map<int, long long> color_count;
    for (int i = 0; i < n; i++) color_count[read()]++;
    // for (auto it = color_count.begin(); it != color_count.end(); it++) {
    // result += it->second * (it->second - 1) / 2 % 1000000007;
    for (int i = 0; i < 1000001; i++) {
        if (color_count[i] == 0) continue;
        result = (result + (long long)color_count[i] * ((long long)color_count[i] - 1) / 2) % 1000000007;
    }
    cout << result << "\n";
    return 0;
}