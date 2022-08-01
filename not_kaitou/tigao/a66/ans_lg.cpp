#include<iostream>
#include<cstdio>
using namespace std;
int n,T,k,ans,f[2000],v[1000],h[1000];
int main() {
    scanf("%d%d%d",&n,&T,&k);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&v[i],&h[i]);
        for (int j=h[i];j<=T*5/4;j++)
        f[j]=max(f[j],f[j-h[i]]+v[i]);
    }
    ans=f[T];
    for (int i=1;i<=n;i++)
    if (h[i]>=k) ans=max(ans,f[(T-h[i])*5/4]+v[i]);
    printf("%d\n",ans);
    return 0;
}
