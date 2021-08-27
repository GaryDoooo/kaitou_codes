#include <bits/stdc++.h>
using namespace std;
struct cube {
    int len2tail = 0, head, tail;
};
static cube c[30005];
int n, x, y;
char command;
void find_head_tail(int x, int *head, int *tail) {
    while (c[*head].head != *head) *head = c[*head].head;
    while (c[*tail].tail != *tail) *tail = c[*tail].tail;
}
int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < 30005; i++) {c[i].head = c[i].tail = i;}
    for (int i = 0; i < n; i++) {
        scanf("%c", &command);
        if (command == 'M') {
            scanf(" %d %d\n", &x, &y);
            int bottom_head = y, bottom_tail = y, top_head = x, top_tail = x;
            find_head_tail(y, &bottom_head, &bottom_tail);
            find_head_tail(x, &top_head, &top_tail);
            c[bottom_head].head = top_head;
            c[top_tail].tail = bottom_tail;
            c[top_head].tail = bottom_tail;
            c[top_head].len2tail += c[bottom_head].len2tail + 1;
            c[top_tail].len2tail = c[bottom_head].len2tail + 1;
        } else {
            scanf(" %d\n", &x);
            int end = x, cnt = 0;
            while (c[end].tail != end) {
                cnt += c[end].len2tail;
                end = c[end].tail;
            }
            c[x].tail = end; c[x].len2tail = cnt;
            printf("%d\n", cnt);
        }
    }
    return 0;
}