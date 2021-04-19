#include <cstdio>
#include "nanosecond_timer.hpp"
using namespace std;

int brute_force(int m, int n) {
    int res = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n - i; j++) {
            // if (n - i - j >= 0)
            if (i * 5 + j * 3 + n - i - j == m) res++;
        }
    return res;
}

int brute_force_less(int m, int n) {
    int res = 0, t1, t2;
    if (n * 5 < m) return 0;
    for (int i = 0; (t1 = i * 5) <= m; i++)
        for (int j = 0; (t2 = j * 3 + t1) <= m and i + j <= n; j++)
            if (t2 + n - i - j == m) res++;
    return res;
}

int main() {
    int N                         = 1000;
    unsigned long long int timer1 = 0, timer2 = 0;
    nanosecond_timer timer;
    for (int m = 1; m < N; m += 10) {
        for (int n = 1; n < N; n += 10) {
            //
            timer.start();
            int a = brute_force(m, n);
            timer1 += timer.stop();
            //////////////
            timer.start();
            int b = brute_force_less(m, n);
            timer2 += timer.stop();
            /////////////
            if (a != b) printf("m=%d n=%d a=%d b=%d\n", m, n, a, b);
        }
    }
    printf("t1=%4.2fs\nt2=%4.2fs\n", (float)timer1 / 1e9, (float)timer2 / 1e9);
}
// future<int> ret_a = async(brute_force, m, n);
// future<int> ret_b = async(brute_force_less, m, n);
// int b             = ret_b.get();
// int a = ret_a.get();
