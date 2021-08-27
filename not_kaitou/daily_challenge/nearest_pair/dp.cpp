#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int M=5005;//不知道为什么1005会RE
struct edge{
    int to,nxt,w;
}e[M];
int head[M],cnt1;
void link(int u,int v,int w){
    e[++cnt1].to=v;
    e[cnt1].w=w;
    e[cnt1].nxt=head[u];
    head[u]=cnt1;
}
int n,u,v,w,dp[M],ans=1e7;//dp[i]是i到i子树内一点距离最小值
void dfs(int u,int fa){
    for(int i=head[u];i;i=e[i].nxt){//遍历u子节点
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        ans=min(ans,dp[u]+e[i].w+dp[v]);//当前距离+之前最大（u为此链拐点，dp[u]为0
                                        //意味着这条链没有拐点）
        dp[u]=min(dp[u],e[i].w+dp[v]);//更新最大值
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        ans=min(ans,w);//dp初始化为0是因为可以不选，但答案不能为0
        link(u,v,w);
        link(v,u,w);
    }
    dfs(1,0);
    printf("%d\n",ans);
}

