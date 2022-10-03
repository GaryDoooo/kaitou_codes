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
    vector<vector<int>>record;
    int n = read();
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = read();
    int hits = 0, current_height;
    while (hits < n) {
        current_height = 3000000;
        vector<int> temp;
        for (int i = 0;  i < n; i++) {
            if (a[i]) {
                if (current_height >= a[i]) {
                    current_height = a[i];
                    hits++;
                    a[i] = 0;
                    temp.push_back(current_height);
                }
            }
        }
        record.push_back(temp);
    }
    cout << record.size() << endl;
    for (int i = 0; i < record.size(); i++) {
        cout << i + 1 << ":";
        for (int j : record[i]) cout << j << " ";
        cout << endl;
    }
    return 0;
}