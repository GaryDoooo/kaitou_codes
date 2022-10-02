#include <bits/stdc++.h>
using namespace std;
int a[100005], sum[100005], qu;

bool cmp (int a, int b) {
    return (a > b);
}

int main(){
    FILE *fp;
    FILE *fp2;
    fp = fopen("eat.in", "r");
    fp2 = fopen("eat.out", "w");
    int n, q;
    fscanf(fp, "%d %d", &n, &q);
    for (int i = 1; i <= n; i++){
        fscanf(fp, "%d", &a[i]);
    }
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + a[i];
    }
    for (int i = 1; i <= q; i++){
        fscanf(fp, "%d", &qu);
        int res = (lower_bound(sum + 1, sum + n + 1, qu) - (sum+1)) + 1;
        if (res <= n){
            fprintf(fp2, "%d\n", res);
        }else{
            fprintf(fp2, "-1\n");
        }
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}