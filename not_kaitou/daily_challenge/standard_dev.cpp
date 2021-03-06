#include <bits/stdc++.h>
using namespace std;
// int convert(string const &s) {
//     int res;
//     sscanf(s.c_str(), "%d", &res);
//     return res;
// }
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int n, input;
    scanf("%d\n", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = read();
    double mean = accumulate(v.begin(), v.end(), 0) / (double)n;
    double sum = 0;
    for (auto i : v)
        sum += (i - mean) * (i - mean);
    printf("%.2f\n", sqrt(sum / n));
}