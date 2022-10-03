#include <stdio.h>
using namespace std;
int v[2005], n, result;
int res[2005][2005]; 
// res[head][tail]記錄在剩餘以head開頭tail結束的零食時，前記最大銷售額

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    for (int day = 1; day <= n; day++) {
        for (int head = 1, tail = n - day + 1; tail <= n; head++, tail++) {
            res[head][tail] =
                max(res[head - 1][tail] + (day - 1) * v[head - 1],
                    res[head][tail + 1] + (day - 1) * v[tail + 1]);
            // 達到當前狀態，要麼是上一天賣掉head-1那個零食
            // 要麼是賣掉了tail+1那個。取兩種可能性下的最大值
            if (day == n) {
                result = max(result, n * v[head] + res[head][tail]);
            }
        }
    }
    printf("%d\n", result);
}
