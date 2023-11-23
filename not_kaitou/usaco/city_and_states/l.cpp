#include <bits/stdc++.h>
using namespace std;
int n;
// struct coord{
//     int x, y, vis = 0;
// };
// vector<coord> e[30][30];
map<string, int> a;

string flips(string a){
    return a.substr(2, 2) + a.substr(0, 2);
}

int main(){
//    freopen("citystate.out", "w", stdout);
  //  freopen("citystate.in", "r", stdin);
    scanf("%d",&n);
    string tempc, temps;
    for (int i = 1; i <= n; i++){
        cin >> tempc >> temps;
        tempc = tempc.substr(0, 2);
        if (tempc != temps){
            auto i = a.find(tempc + temps);
            if (i == a.end()){
                a[tempc + temps] = 1;
            }else{
                a[tempc + temps]++;
            }
        }
        // coord tc, ts;
        // tc.x = tempc[0] - 'A'; tc.y = tempc[1] - 'A';
        // ts.x = temps[0] - 'A'; ts.y = temps[1] - 'A';
        // e[tc.x][tc.y].push_back(ts);
    }
    int ans = 0;
    for (auto const& cs : a){
        string csr = flips(cs.first);
        auto fr = a.find(csr);
        if (fr != a.end()){
            ans += (a[csr] * cs.second);
        }
    }
    // int ans = 0;
    // for (int i = 0; i < 26; i++){
    //     for (int j = 0; j < 25; j++){
    //         for (int k = 0; k < e[i][j].size(); k++){
    //             if (!e[i][j][k].vis){
    //                 int tx = e[i][j][k].x;
    //                 int ty = e[i][j][k].y;
    //                 e[i][j][k].vis = 1;
    //                 for (int l = 0; l < e[tx][ty].size(); l++){
    //                     if (e[tx][ty][l].x == tx and e[tx][ty][l].y == ty){
    //                         ans++;
    //                         e[tx][ty][l].vis = 1;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    printf("%d\n", ans/2);
    return 0;
}
