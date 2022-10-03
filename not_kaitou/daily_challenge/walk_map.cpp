#include <bits/stdc++.h>
using namespace std;
int h, w, d[] = {1, -1, 0, 0};
int *a, *res;
inline int read() {
    int x = 0;//, f = 1;
    char ch = getchar();
    while (ch < 47) ch = getchar();
    while (ch > 47) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;
}
int get_steps(int pos) {
    int result = 1, new_pos;
    for (int i = 0; i < 4; i++) {
        new_pos = pos + d[i];
        if (a[new_pos])
            if (a[pos] > a[new_pos])
                if (a[pos] % a[new_pos] == 0) {
                    if (!res[new_pos]) res[new_pos] = get_steps(new_pos);
                    result = max(result, res[new_pos] + 1);
                }
    }
    return result;
}
int main() {
    h = read(), w = read();
    int mem_size = (h + 2) * (w + 2) * sizeof(int);
    d[2] = w + 2; d[3] = -w - 2;
    a = (int *)malloc(mem_size);
    res = (int *)malloc(mem_size);
    memset(a, 0, mem_size);
    memset(res, 0, mem_size);
    for (register int y = w + 2; y <= (h) * (w + 2); y += w + 2)
        for (register int x = 1; x <= w; x++)
            a[y + x] = read();
    mem_size /= sizeof(int);
    for (register int i = w + 3; i < mem_size; i++)
        if (a[i]) if (!res[i]) res[i] = get_steps(i);
    cout << *max_element((int *)res, (int *)res + mem_size);
}