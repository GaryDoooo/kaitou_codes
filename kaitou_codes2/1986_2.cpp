#include <bits/stdc++.h>
using namespace std;
long long a;

bool g (long long n){
    while (n%2 == 0){
        n /= 2;
    }
    if (n > 3){
        return false;
    }
    return true;   
}

int main()
{
    FILE *fp;
    FILE *fp2;
    int t;
    fp = fopen("prime.in","r");
    fp2 = fopen("prime.out","w");
    fscanf(fp, "%d", &t);
    for (int i = 1; i <= t; i++){
        fscanf(fp, "%lld", &a);
        if (g(a)){
            fprintf(fp2, "0\n");
        }else{
            fprintf(fp2, "1\n");
        }
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
