#include <bits/stdc++.h>
using namespace std;
int h, w, a[2550], spot_cnt;
vector<int> spot[5];

void read_map() {
    char c;
    for (int i = 0; i < h * w; i++) {
        do {
            c = getchar();
        } while (c != '.' and c != 'X');
        a[i] = (c == 'X');
    }
}

void dfs(int pos, int spot_num) {
    if (a[pos] == 0) return;
    a[pos] = 0;
    spot[spot_num].push_back(pos);
    int d[4] = {-1, 1, -w, w};
    for (int i = 0; i < 4; i++) {
        if (pos % w == 0 and i == 0) continue;
        if (pos % w == w - 1 and i == 1) continue;
        int new_pos = pos + d[i];
        if (new_pos < 0 or new_pos >= h * w) continue;
        dfs(new_pos, spot_num);
    }
}

int distance(int pos1, int pos2) {
    return abs(pos1 % w - pos2 % w) + abs(pos1 / w - pos2 / w) - 1;
}

int find_min_distance(vector<int> &a, vector<int> &b) {
    int res = 100000;
    for (auto p1 : a)
        for (auto p2 : b) res = min(res, distance(p1, p2));
    return res;
}

int connect(int s1, int s2, int s3) {
    // connect spot1 and spot2 first in to a whole
    // with Manhat... min distance and connect spot 3
    int min_dis_s1_s2 = find_min_distance(spot[s1], spot[s2]);
    vector<int> spot_1plus2(spot[s1]);
    spot_1plus2.insert(spot_1plus2.end(), spot[s2].begin(), spot[s2].end());
    for (auto pos1 : spot[s1])
        for (auto pos2 : spot[s2])
            if (distance(pos1, pos2) == min_dis_s1_s2) {
                int x1 = pos1 % w, x2 = pos2 % w, y1 = pos1 / w, y2 = pos2 / w;
                int xs = min(x1, x2), xe = max(x1, x2);
                int ys = min(y1, y2), ye = max(y1, y2);
                for (int x = xs; x <= xe; x++)
                    for (int y = ys; y <= ye; y++)
                        spot_1plus2.push_back(y * w + x);
            }
    return min_dis_s1_s2 + find_min_distance(spot[s3], spot_1plus2);
}

int main() {
    scanf("%d %d\n", &h, &w);
    read_map();
    for (int i = 0; i < h * w; i++)
        if (a[i]) dfs(i, ++spot_cnt);
    printf("%d\n",
           min(min(connect(1, 2, 3), connect(2, 3, 1)), connect(3, 1, 2)));
}
