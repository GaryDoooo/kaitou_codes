#include <bits/stdc++.h>
using namespace std;
const int N=200005,B=2000005;
int Bin[23],Log[N];
int n,m,Start[N],f[N][23],Last[B];
int main()
{
    int i,j;
    Bin[0]=1;
    for(i=1;i<=19;i++)
    {
        Bin[i]=Bin[i-1]<<1;
    }
    Log[0]=-1;
    for(i=1;i<N;i++)
    {
        Log[i]=Log[i>>1]+1;
    }
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        x+=1000000;
        Start[i]=max(Start[i-1],Last[x]+1);
        f[i][0]=i-Start[i]+1;
        Last[x]=i;
    }
    for(i=1;i<=19;i++)
    {
        for(j=1;j+Bin[i]-1<=n;j++)
        {
            f[j][i]=max(f[j][i-1],f[j+Bin[i-1]][i-1]);
        }
    }
    for(i=1;i<=m;i++)
    {
        int ql,qr,Pos,ans=0;
        scanf("%d%d",&ql,&qr);
        ql++;
        qr++;
        if(Start[qr]<=ql) Pos=qr+1;
        else Pos=lower_bound(Start+1,Start+n+1,ql)-Start;
        if(Pos>ql)
        {
            ans=(Pos-1)-ql+1;
        }
        if(Pos<=qr)
        {
            int oo=Log[qr-Pos+1];
            ans=max(ans,max(f[Pos][oo],f[qr-Bin[oo]+1][oo]));
        }
        printf("%d\n",ans);
    }
}
/*
input
9 2
2 5 4 1 2 3 6 2 4
0 8
2 6
output
6
5
*/
