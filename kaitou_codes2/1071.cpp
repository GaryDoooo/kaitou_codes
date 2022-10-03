#include <iostream>
#include <cstring>
using namespace std;
int f[405][405], w[55], v[55], c[55];
int main(){
    int n, mv, mw;
    cin >> mv >> mw >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i] >> w[i] >> c[i];
    }
    int ans = -1;
    memset(f, 128, sizeof(f));
    f[0][0] = 0;
    for (int k = 1; k <= n; k++){
        for (int i = mv; i >= v[k]; i--){
            for (int j = mw; j >= w[k]; j--){
                f[i][j] = max(f[i][j], f[i-v[k]][j-w[k]] + c[k]);
                ans = max(ans, f[i][j]);
            }  
        }
    }
    cout << ans;
    return 0;
}