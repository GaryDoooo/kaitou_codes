#include <iostream>
using namespace std;
int a[25][25];
int mx[9] = {1, 2, 2, 1, -1, -2, -2, -1,0};
int my[9] = {-2, -1, 1, 2, 2, 1, -1, -2,0};
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int xb, yb, xc, yc;
long long res[25][25];


long long dfs(int x, int y){
    // cout << "here" << endl;
    if (res[x][y] != -1) return res[x][y];
    if (x == xb and y == yb) return 1;
    if (x > xb or y > yb){
        a[x][y] = 0;
    }
    long long ans = 0;
    a[x][y] = 1;
    for (int d = 0; d < 2; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        // if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
        if (a[nx][ny] == 0){
            if (nx >= 0 && nx <=  xb && ny >= 0 && ny <= yb) {
                a[nx][ny] = 1; 
                ans += dfs(nx, ny);
                a[nx][ny] = 0;
            }
        }
    }
    return res[x][y] = ans;
}

int main(){
    for (int i = 0; i <= 25; i++){
        for (int j = 0; j <= 25; j++){
            res[i][j] = -1;
        }
    }
    cin >> xb >> yb >> xc >> yc;
    
    for (int i = 0; i < 9; i++){
        int nx = xc + mx[i];
        int ny = yc + my[i];
        if (nx >= 0 && nx <= xb && ny >= 0 && ny <= yb) {
            a[nx][ny] = 1;
        }
    }
    
    a[0][0] = 1;
    cout << dfs(0, 0) << endl;
    return 0;
}