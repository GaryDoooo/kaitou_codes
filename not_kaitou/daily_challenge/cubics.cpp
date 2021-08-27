#include <bits/stdc++.h>
using namespace std;
struct cube {
    int nxt = 0, len2tail = 0, head, tail;
};
static cube c[30005];
int n, x, y;
char command;
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
inline int read() {
    int x = 0;//, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) { ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;// * f;
}
int main() {
    n = read();
    for (int i = 0; i < 30005; i++) {c[i].head = c[i].tail = i;}
    for (int i = 0; i < n; i++) {
        command = getchar(); getchar();
        if (command == 'M') {
            x = read(); y = read();
            int head = y, end = x;
            while (c[head].head != head) head = c[head].head;
            while (c[end].tail != end) end = c[end].tail;
            c[end].nxt = head;
            c[head].head = c[x].head;
            c[end].tail = c[head].tail;
            c[end].len2tail = c[head].len2tail + 1;
            c[c[x].head].tail = c[head].tail;
            c[c[x].head].len2tail += c[head].len2tail;
        } else {
            x = read();
            int end = x, cnt = 0;
            while (c[end].tail != end) {
                cnt += c[end].tail;
                end = c[end].tail;
            }
            // while (c[end].nxt) {
            //     cnt++; end = c[end].nxt;
            //     if (c[c[end].tail].tail == c[end].tail) {
            //         cnt += c[end].len2end;
            //         break;
            //     }
            // }
            write(cnt); putchar('\n');
        }
    }
    return 0;
}