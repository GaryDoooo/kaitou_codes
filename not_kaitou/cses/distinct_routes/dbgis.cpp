#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=505;

int adj[N][N], oadj[N][N], vis[N][N];
int id[N], dep[N];
int n;

bool reachable(){
        for(int i=1;i<=n;i++) dep[i]=0;
        dep[1]=1;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
                int i=q.front();
                q.pop();
                for(int j=1;j<=n;j++){
                        if (adj[i][j]&&!dep[j]){
                                dep[j]=dep[i]+1;
                                q.push(j);
                        }
                }
        }
        return dep[n];
}

int dfs(int x, int f){
        if (x==n) return f;
        ll flow=0;
        for(;id[x]<=n;id[x]++){
                if (dep[x]+1==dep[id[x]]&&adj[x][id[x]]){
                        flow=dfs(id[x], min(f, adj[x][id[x]]));
                        if (flow){
                                adj[x][id[x]]-=flow;
                                adj[id[x]][x]+=flow;
                                break;
                        }
                }
        }
        return flow;
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int m;
        cin >> n >> m;
        for(int i=0;i<m;i++){
                int a, b;
                cin >> a >> b;
                adj[a][b]++;
                oadj[a][b]++;
        }
        int k=0;
        while(reachable()){
                for(int i=1;i<=n;i++) id[i]=1;
                int t;
                while(t=dfs(1, 1e18)) k+=t;
        }
        cout << k << '\n';
        while(k--){
                vector<int> tmp;
                int i=1;
                tmp.push_back(i);
                while(i!=n){
                        for(int j=1;j<=n;j++){
                                if (!adj[i][j]&&oadj[i][j]&&!vis[i][j]){
                                        tmp.push_back(j);
                                        vis[i][j]=1;
                                        i=j;
                                        break;
                                }
                        }
                }
                cout << tmp.size() << '\n';
                for(auto e:tmp) cout << e << ' ';
                cout << '\n';
        }
}

