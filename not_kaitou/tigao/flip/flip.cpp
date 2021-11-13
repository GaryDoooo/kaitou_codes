#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    putchar(' ');
}
////////////////////////
struct range {
    int left, right;  //, rc_left, rc_right, left_index;
    bool operator<(range const& o) const {
        return (left < o.left or (left == o.left and right < o.right));
    }
};
// bool cmp(range const& a, range const& b) { return a.right < b.right; }
int main() {
    int n = read(), m = read();
    range f[m + 1];
    for (int i = 0; i < m; i++) {
        f[i] = {read(), read()};
    }
    sort(f, f + m);
    f[m] = {MAX_INT, MAX_INT};
    // for (int i = 0; i < m; i++) f[i].left_index = i;
    // range dummy[m];
    // memcpy(dummy, f, m * sizeof(range));
    // sort(dummy, dummy + m, cmp);
    // for (int i = 0;i < m-1; i++){
    //     f[dummy[i].left_index].rc_right=dummy[i+1].left_index;
    //     f[dummy[i+1].left_index].rc_left=dummy[i].left_index;
    // }
    // unsigned seed =
    // std::chrono::system_clock::now().time_since_epoch().count();
    multiset<int> collected_right;
    int res = 0, left = 0, right = 0;  //, flip_count;
    for (int i = 1; i <= n; i++) {
        if (i < f[left].left) continue;
        // vint buffer;
        while (f[right].left <= i) {
            collected_right.insert(f[right].right);
            // buffer.push_back(f[right].right);
            right++;
        }
        // if (buffer.size() > 0) {
        //     // shuffle(buffer.begin(), buffer.end(),
        //     // default_random_engine(seed));
        //     sort(buffer.begin(), buffer.end());
        //     collected_right.insert(buffer.begin(), buffer.end());
        //     // collected_right.insert(1);
        //     buffer.clear();
        // }
        // while (f[left].right < i) {
        //     collected_right.erase(collected_right.find(f[left].right));
        //     left++;
        // }
        auto it = collected_right.lower_bound(i);
        res += distance(it, collected_right.end()) & 1;
        // while (f[right + 1].left <= i and f[right + 1].right >= i) right++;
        // res += (right - left + 1) & 1;
        cout << left << " " << right << " " << i << " " << res << endl;
    }
    cout << res;
}
