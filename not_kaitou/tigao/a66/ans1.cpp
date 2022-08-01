#include<bits/stdc++.h>
#define v first 
#define h second 
using namespace std; 
const int N=105; const int M=1050; int n,t,k; typedef pair<int,int> PII; PII w[N]; int big[N]; int cnt; int f[M]; int ans1,ans2; int main(){ cin>>n>>t>>k; for(int i=1;i<=n;i++){ scanf("%d%d",&w[i].v,&w[i].h); if(w[i].h>=k) big[++cnt]=i; } for(int i=1;i<=n;i++){ if(w[i].h>=k) continue; for(int j=w[i].h;j<=t;j++){ f[j]=max(f[j],f[j-w[i].h]+w[i].v); } } ans1=f[t]; for(int k=1;k<=cnt;k++){ memset(f,0,sizeof(f)); int p=big[k]; int m=t-w[p].h; if(m<0) continue; for(int i=1;i<=n;i++){ for(int j=w[i].h*4/5;j<=m;j++){ f[j]=max(f[j],f[j-w[i].h*4/5]+w[i].v); } } ans2=max(ans2,f[m]+w[p].v); } cout<<max(ans1,ans2); return 0; }

