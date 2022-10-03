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
    // vector<int> systems{3000000};
    int n = read();
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = read();
    // for (int i = 0; i < n; i++) {
    //     int new_missle = read();
    //     sort(systems.begin(), systems.end());
    //     auto it = upper_bound(systems.begin(), systems.end(), new_missle);
    //     if (it != systems.begin())
    //         if (*(it - 1) == new_missle) it--;
    //     if (it == systems.end()) systems.push_back(3000000);
    //     *it = new_missle;
    // }
    // cout << systems.size() << endl;
    int systems = 0, hits = 0, current_height;
    while (hits < n) {
        systems++; current_height = 3000000;
        for (int i = 0;	 i < n; i++) {
            if (a[i]) {
                if (current_height >= a[i]) {
                    current_height = a[i];
                    hits++;
                    a[i] = 0;
                }
            }
        }
    }
    cout << systems << endl;
    return 0;
}