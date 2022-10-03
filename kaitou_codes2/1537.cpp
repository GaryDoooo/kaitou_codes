#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

int main(){
    // freopen("prime.in", "r", stdin);
    // freopen("prime.out", "w", stdout);
    FILE *fp;
    fp = fopen("square.in","r");
    
    long long n;
    // cin >> n;
    fscanf(fp, "%lld", &n);
    fclose(fp);
    long long ans = 0;
    for (long long i = 1; i * i <= n; i++){
        long long j = (i*i)%MOD;
        ans = (ans + (((n-j+1)%MOD)*j)%MOD)%MOD;
    }
    fp = fopen("square.out","w");
    // cout << ans;
    fprintf(fp, "%lld\n", ans);
    fclose(fp);
    return 0;
}