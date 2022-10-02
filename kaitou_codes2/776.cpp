#include <iostream>
using namespace std;
int f[100005], w[2005], v[2005];

int main(){
    int t, m;
    cin >> t >> m;
    int ans = -1;
    for (int i = 1; i <= m; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = w[i]; j <= t; j ++){
            f[j] = max(f[j], f[j-w[i]] + v[i]);
            ans = max(ans, f[j]);
        }
    }
    cout << ans;
    return 0;
}