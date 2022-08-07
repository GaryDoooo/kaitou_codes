#include <iomanip>
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
    cout << fixed;
    cout << setprecision(1);
    //    printf("%.1f\n",
    cout << (double)sum / ((double)n / (double)m);  //);
}
