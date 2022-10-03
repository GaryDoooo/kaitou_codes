#include <bits/stdc++.h>
using namespace std;
int n, subtree_size[1005];
vector<int> a(1005, 0);
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
void split_tree(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin >= end) return;
    auto min_position = min_element(begin, end);
    subtree_size[*min_position] = end - begin;
    split_tree(begin, min_position);
    split_tree(min_position + 1, end);
}
int main() {
    n = read();
    for (int i = 0; i < n; i++) a[i] = read();
    split_tree(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        cout << subtree_size[i] << " ";
    } cout << endl;
    return 0;
}