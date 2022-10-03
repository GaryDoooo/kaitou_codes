#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
struct item {
    int w, v , s1 , s2;
};
bool cmp(item const &a, item const &b) { return a.w < b.w; }
int maxw, n, master_index = 0, son_index = 0, bestv = 0, father;
item itm[61];
unsigned int record_w[61], record_v[61] = {0};
void dfs(int index, int weight, int value, vector<item> &itm2) {
    if (weight > maxw) return;
    if (weight >= record_w[index] and value <= record_v[index]) return;
    record_w[index] = weight; record_v[index] = value;
    if (weight + itm[index].w > maxw or index > n) {
        bestv = max(bestv, value);
        return;
    }
    dfs(index + 1, weight, value, itm2);
    if (itm[index].s1 >= 0) dfs(index + 1, weight + itm[index].w, value + itm[index].v, itm2);
    if (itm[index].s1 > 0) dfs(index + 1, weight + itm[index].w + itm2[itm[index].s1].w,
                                   value + itm[index].v + itm2[itm[index].s1].v, itm2);
    if (itm[index].s2 > 0) {
        dfs(index + 1, weight + itm[index].w + itm2[itm[index].s2].w, value + itm[index].v + itm2[itm[index].s2].v, itm2);
        dfs(index + 1, weight + itm[index].w + itm2[itm[index].s1].w + itm2[itm[index].s2].w,
            value + itm[index].v + itm2[itm[index].s1].v + itm2[itm[index].s2].v, itm2);
    }
}
int main() {
    maxw = read(), n = read();
    memset(itm, 0, sizeof(itm));
    memset(record_w, 255, sizeof(record_w));
    for (int i = 1; i <= n; i++) {
        itm[i].w = read() ; itm[i].v = read() * itm[i].w;
        father = read();
        if (father) {
            itm[i].s1 = -1;
            if (itm[father].s1) itm[father].s2 = i;
            else itm[father].s1 = i;
        }
    }
    vector<item> itm2(itm, itm + n + 1);
    sort(itm, itm + n + 1, cmp);
    dfs(1, 0, 0, itm2);
    cout << bestv << endl;
}