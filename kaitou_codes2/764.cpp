#include <iostream>
#include <set>
#include <string>
using namespace std;
int a[10][10];
set<string> ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};


void dfs(int x, int y, string s){
    if (s.length() == 6) {
        ans.insert(s);
        return;
    }
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5) {
            dfs(nx, ny, s + to_string(a[nx][ny]) );
        }
    }
}

int main(){
    for (int y = 1; y <= 5; y++){
        for (int x = 1; x <= 5; x++){
            cin >> a[x][y];
        }
    }

    for (int y = 1; y <= 5; y++){
        for (int x = 1; x <= 5; x++){
            dfs(x, y, to_string(a[x][y]));
        }
    }
    
    cout << ans.size() << endl;
    return 0;
}