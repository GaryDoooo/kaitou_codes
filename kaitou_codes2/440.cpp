#include <iostream>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int xc, yc;
int h, w;
int a[1005][1005];
bool flag[1005][1005];


long long dfs(int x, int y){
    long long ans = 1;
    flag[x][y] = true;
    // for (int y = 1; y <= h; y++){
    //     for (int x = 1; x <= w; x++){
    //         cout << flag[x][y] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        // if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
        if (a[nx][ny] <= a[x][y] and flag[nx][ny] == false){
            if (nx > 0 && nx <= w && ny > 0 && ny <= h) {
                flag[nx][ny] = true; 
                ans += dfs(nx, ny);
            }
        }
    }
    return ans;
}

int main(){
    cin >> h >> w >> xc >> yc;
    for (int y = 1; y <= h; y++){
        for (int x = 1; x <= w; x++){
            flag[x][y] = false;
            cin >> a[x][y];
        }
    }
    cout << dfs(yc, xc);
    return 0;
}