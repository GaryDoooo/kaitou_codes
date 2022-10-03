#include <iostream>
using namespace std;
long long f[100005], w[2005];

int main(){
    long long m, t;
    cin >> m >> t;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    f[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= w[i]; j--){
            f[j] += f[j-w[i]];
        }
    }
    // long long ans = 0;
    // for (int i = 1; i <= t; i++) {
    //     ans += f[i];
    // }
    // cout << ans;
    cout << f[t];
    return 0;
}