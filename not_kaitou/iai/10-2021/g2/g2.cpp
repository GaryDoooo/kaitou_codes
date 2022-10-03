#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
int target[11], target_len = 0, first_occurrence[200];
int a[100] = {0}, same_to[100];
int d[8]   = {1, -1, 10, -10, 9, 11, -9, -11};
int cache[100];
ull bitadd[100], bitdel[100];
int find_head(int i) {
    while (i != same_to[i]) i = same_to[i];
    return i;
}
ull count(int start, int pos) {
    if (pos >= target_len) return 1;
    int index = find_head(start);
    if (pos == 0) {
        if (cache[index] >= 0) return cache[index];
    }
    ull res  = 0;
    a[start] = 0;
    for (int i = 0; i < 8; i++) {
        int next = start + d[i];
        if (a[next] == target[pos + 1]) res += count(next, pos + 1);
    }
    a[start] = target[pos];
    if (pos == 0) cache[index] = res;
    return res;
}
int main() {
    string input;
    cin >> input;
    memset(cache, 255, sizeof(cache));
    for (int i = 0; i <= (target_len = input.length() - 1); i++) {
        target[i] = (int)input[i];
    }
    for (int y = 1; y <= 8; y++) {
        cin >> input;
        for (int x = 1; x <= 8; x++) {
            a[(y * 10) + x]    = (int)input[x - 1];
            bitadd[y * 10 + x] = (1UL << ((y - 1) * 8 + x - 1));
            bitdel[y * 10 + x] = ~bitadd[y * 10 + x];
        }
    }
    ull res = 0;
    for (int i = 0; i < 100; i++) same_to[i] = i;
    // vertical mirror
    bool same = true;
    for (int y = 1; y <= 8; y++)
        for (int x = 1; x <= 4; x++)
            if (a[(y * 10) + x] != a[(y * 10) + (9 - x)]) same = false;
    if (same) {
        for (int y = 1; y <= 8; y++)
            for (int x = 1; x <= 4; x++)
                same_to[(y * 10) + (9 - x)] = (y * 10) + x;
    }
    // horizontal mirror
    same = true;
    for (int y = 1; y <= 4; y++)
        for (int x = 1; x <= 8; x++)
            if (a[(y * 10) + x] != a[((9 - y) * 10) + x]) same = false;
    if (same) {
        for (int y = 1; y <= 4; y++)
            for (int x = 1; x <= 8; x++)
                same_to[(9 - y) * 10 + x] = (y * 10) + x;
    }
    // diagonal mirror
    same = true;
    for (int y = 2; y <= 8; y++)
        for (int x = 1; x < y; x++)
            if (a[y * 10 + x] != a[x * 10 + y]) same = false;
    if (same) {
        for (int y = 2; y <= 8; y++)
            for (int x = 1; x < y; x++) same_to[x * 10 + y] = y * 10 + x;
    }
    // DFS
    struct node {
        ull done, index, pos;
    };
    stack<node> todo;
    vint next[100];
    for (int y = 1; y <= 8; y++)
        for (int x = 1; x <= 8; x++)
            for (int i = 0; i < 8; i++)
                next[y * 10 + x].push_back(y * 10 + x + d[i]);
    for (int i = 0; i < 100; i++)
        if (a[i] == target[0]) {
            int head = find_head(i);
            if (cache[head] >= 0) {
                res += cache[head];
                continue;
            }
            ull temp_res = 0;
            todo.push({bitdel[i], i, 0});
            while (!todo.empty()) {
                node now = todo.top();
                todo.pop();
                for (int nxt : next[now.index])
                    if (bitadd[nxt] & now.done and
                        a[nxt] == target[now.pos + 1]) {
                        if (now.pos + 1 == target_len) {
                            temp_res++;
                            continue;
                        }
                        todo.push({now.done & bitdel[nxt], nxt, now.pos + 1});
                    }
            }
            res += cache[head] = temp_res;
        }
    cout << res;
}
