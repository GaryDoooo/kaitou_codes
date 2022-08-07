#include <iostream>
using namespace std;
int main() {
    int m, n;
    unsigned long long sum, a;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        sum += a;
    }
    printf("%.1f\n", (double)sum / (double)n * (double)m);
}
