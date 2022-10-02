#include <iostream>
using namespace std;
char a[85][1005];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int w, h;

int dfs(int x, int y){
    // for (int y = 1; y <= h; y++){
    //     for (int x = 1; x <= w; x++){
    //         cout << a[y][x];
    //     }
    //     cout << endl;
    // }
    cout << endl;
    int res = 1;
    a[x][y] = '.';
    for (int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 1 && nx <= w && ny >= 1 && ny <= h){
            if (a[nx][ny] == '*'){
                res += dfs(nx, ny);
            }
        }
    }
    
    return res;
}

int main(){
    cin >> w >> h;
    for (int y = 1; y <= h; y++){
        for (int x = 1; x <= w; x++){
            cin >> a[x][y];
        }
    }
    int ans = -1;
    for (int y = 1; y <= h; y++){
        for (int x = 1; x <= w; x++){
            if (a[x][y] == '*'){
                ans = max(ans, dfs(x, y));
            }
        }
    }
    
    cout << ans;
    return 0;
}