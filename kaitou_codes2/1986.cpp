#include <bits/stdc++.h>
using namespace std;
long long a[10005];
int f[10005];

int g (long long n){
    int ans = 0;
    int c = 2;
    while (n > 1){
        if (n % c == 0){
            ans++;
            n /= c;
        }else {
            c++;
        }
    }
    return ans;
}

int main()
{
    // freopen("prime.in", "r", stdin);
    // freopen("prime.out", "w", stdout);
    FILE *fp;
    int t;
    fp = fopen("prime.in","r");
    fscanf(fp, "%d", &t);
    // cin >> t;
    for (int i = 1; i <= t; i++){
        // cin >> a[i];
        fscanf(fp, "%d", &a[i]);
        f[i] = g(a[i]);
    }
    fclose(fp);
    fp = fopen("prime.out", "w");
    bool flag = false;
    for (int i = 1; i <= t; i++){
        int cnt = 1;
        long long eee=1<<(f[i]+1);
        if (eee < a[i]){
            fprintf(fp, "1\n");
        }else{
            fprintf(fp, "0\n");
        }
        // for (long long j = 2; j < a[i]; j *= 2){
        //     if (cnt > f[i]) {
        //         cout << 1 << endl;
        //         flag = true;
        //         break;
        //     }
        //     cnt++;
        // }
        // if (flag == false){
        //     cout << 0 << endl;
        // }
        // flag = false;
    }
    fclose(fp);
    return 0;
}
