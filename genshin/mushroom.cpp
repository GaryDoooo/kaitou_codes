#include <bits/stdc++.h>
#define TARGET 111222
#define START 101212
#define INSERT_ROW1 2
#define INSERT_ROW2 1
#define INSERT_ROW3 2
////////////
using namespace std;
struct node {
    int fa, step, a;
};
node q[1000000];
set<int> s;
int step, father, head = 1, tail;
void print(int a[5][5]) {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) cout << a[y][x] << " ";
        cout << endl;
    }
    cout << endl;
}
int a2i(int a[5][5]) {
    int res = 0;
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++) res += a[y][x] * pow(10, (2 - y) * 3 + x);
    return res;
}

void print2(int now) {
    int a[5][5];
    for (int i = 0; i < 9; i++) {
        a[2 - i / 3][i % 3] = now % 10;
        now                 = now / 10;
    }
    print(a);
}

void put(int b[5][5]) {
    int next = a2i(b);
    if (next == TARGET) {
        print2(TARGET);
        int i = father;
        do {
            print2(q[i].a);
            i = q[i].fa;
        } while (i);
        exit(0);
    }
    if (s.find(next) == s.end()) {
        q[++tail] = {father, step, next};
        s.insert(next);
    }
}

int main() {
    q[++tail] = {0, 0, START};
    s.insert(START);
    while (head <= tail) {
        ;
        int a[5][5], b[5][5];
        node NOW = q[head++];
        int now  = NOW.a;
        father = head - 1, step = NOW.step;
        for (int i = 0; i < 9; i++) {
            a[2 - i / 3][i % 3] = now % 10;
            now                 = now / 10;
        }
        for (int x = 0; x < 3; x++) {
            memcpy(b, a, sizeof(a));
            b[0][x] = INSERT_ROW1;
            b[1][x] = INSERT_ROW2;
            b[2][x] = INSERT_ROW3;
            put(b);
        }
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++) {
                if (y < 2) {
                    memcpy(b, a, sizeof(a));
                    swap(b[y + 1][x], b[y][x]);
                    put(b);
                }
                if (x < 2) {
                    memcpy(b, a, sizeof(a));
                    swap(b[y][x + 1], b[y][x]);
                    put(b);
                }
            }
        for (int y = 0; y < 2; y++)
            for (int x = 0; x < 2; x++) {
                memcpy(b, a, sizeof(a));
                b[y][x] = a[y + 1][x], b[y + 1][x] = a[y + 1][x + 1];
                b[y][x + 1] = a[y][x], b[y + 1][x + 1] = a[y][x + 1];
                put(b);
            }
    }
}
