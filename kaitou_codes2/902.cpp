#include <iostream>
using namespace std;
int f[1005];
int v[1005][1005], w[1005][1005], s[1005];
int n, m, k;

int main() 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        for (int k = 1; k <= s[i]; k++) 
            cin >> w[i][k] >> v[i][k];
    }
    for (int i = 1; i <= n; i++){
        for (int j = m; j >= 0; j--){
            for (int k = 1; k <= s[i]; k++){
                if (w[i][k] > j){
                    continue;
                }
                f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);
            }
        }
    }

    cout << f[m];
    return 0;
}
