#include <bits/stdc++.h>
#define SEG_SIZE 4000
#define SEG_CNT 1005
using namespace std;
int n, q, a, b;
int x[212345];                      // store Xi converted
map<int, int> convert_map;          // convert 1e9 range to 2e5
int convert_idx, prev_idx[212345];  // previous same value position, index is i
int last_idx[212345];     // last time this value position, index is converted
                          // value
vector<int> s[SEG_CNT];   // sorted prev_idx of each segment
vector<int> s2[SEG_CNT];  //
int seg_idx;

void build_segment() {
    int i = 0;
    while (i + SEG_SIZE <= n) {
        seg_idx++;
        for (int j = i + 1; j <= i + SEG_SIZE; j++)
            s[seg_idx].push_back(prev_idx[j]);
        sort(s[seg_idx].begin(), s[seg_idx].end());
        i += SEG_SIZE;
    }
    i       = 0;
    seg_idx = 0;
    while (i + SEG_SIZE / 10 <= n) {
        seg_idx++;
        for (int j = i + 1; j <= i + SEG_SIZE / 10; j++)
            s2[seg_idx].push_back(prev_idx[j]);
        sort(s2[seg_idx].begin(), s2[seg_idx].end());
        i += SEG_SIZE / 10;
    }
}

int seg_cnt(int a, int i) {
    seg_idx = i / SEG_SIZE + 1;
    // cout << seg_idx << " ";
    return (int)distance(s[seg_idx].begin(),
                         lower_bound(s[seg_idx].begin(), s[seg_idx].end(), a));
}

int seg_cnt2(int a, int i) {
    seg_idx = i / (SEG_SIZE / 10) + 1;
    // cout << seg_idx << " ";
    return (int)distance(
        s2[seg_idx].begin(),
        lower_bound(s2[seg_idx].begin(), s2[seg_idx].end(), a));
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (convert_map[a] == 0) {
            x[i] = convert_map[a] = ++convert_idx;
            last_idx[convert_idx] = i;
        } else {
            x[i]           = convert_map[a];
            prev_idx[i]    = last_idx[x[i]];
            last_idx[x[i]] = i;
        }
    }
    build_segment();
    while (q--) {
        // if (q < 200000 - 30) continue;
        scanf("%d %d", &a, &b);
        int cnt = 0;
        // for (int i = a + 1; i <= b; i++) cnt += (prev_idx[i] < a);
        int first_i_in_seg = (a / SEG_SIZE + (a % SEG_SIZE > 1)) * SEG_SIZE + 1;
        int last_i_in_seg  = b - (b % SEG_SIZE);
        int seg_size2      = SEG_SIZE / 10;
        int first_i_in_seg2 =
            (a / seg_size2 + (a % seg_size2 > 1)) * seg_size2 + 1;
        int last_i_in_seg2 = b - (b % seg_size2);
        // cout << a << " " << b << endl;
        // cout << a / SEG_SIZE << endl;
        // cout << first_i_in_seg << " " << last_i_in_seg << endl;
        for (int i = a; i <= b; i++) {
            if ((i >= first_i_in_seg) && (i <= last_i_in_seg)) {
                int a1 = seg_cnt(a, i);
                // int a2 = 0;
                // for (int j = i; j < i + SEG_SIZE; j++) a2 += (prev_idx[j] <
                // a); if (a2 != a1) {
                //     cout << a1 << " " << a2 << endl;
                //     seg_idx = i / SEG_SIZE + 1;
                //     auto it =
                //         upper_bound(s[seg_idx].begin(), s[seg_idx].end(), a);
                //     cout << *it << " " << *(--it) << endl;
                //     // for (auto j : s[seg_idx]) cout << j << " ";
                //     // cout << endl;
                // }
                cnt += a1;
                // cout << i << " ";
                i += SEG_SIZE - 1;
            } else if ((i >= first_i_in_seg2) and (i <= last_i_in_seg2)) {
                cnt += seg_cnt2(a, i);
                i += seg_size2 - 1;
            } else {
                cnt += (prev_idx[i] < a);
            }
            // cout << cnt << " ";
        }
        printf("%d \n", cnt);
    }
}
