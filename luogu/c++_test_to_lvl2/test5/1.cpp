#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v;
    int e;
    for (int i = 0; i < 5; i ++) {
        vector<int> temp;
        for (int j = 0; j < 5; j ++) {
            cin >> e;
            temp.push_back(e);
        }
        v.push_back(temp);
    }
    ////////////////////////////////
    for (int y = 0; y < 5; y ++) {
        int row_max_val = 0;
        int row_max_ind;
        for (int x = 0; x < 5; x ++) {
            if (v[y][x] > row_max_val) {
                row_max_val = v[y][x];
                row_max_ind = x;
            }
        }
        vector<int> c;
        for (int i = 0; i < 5; i ++) {
            c.push_back(v[i][row_max_ind]);
        }
        int col_min_val = 1e8;
        int col_min_ind;
        for (int i = 0; i < 5; i ++) {
            if (c[i] < col_min_val) {
                col_min_val = c[i];
                col_min_ind = i;
            }
        }
        if (c[col_min_ind] == v[y][row_max_ind]) {
            cout << col_min_ind + 1 << " " << row_max_ind + 1 << " " << v[col_min_ind][row_max_ind] << endl;
            return 0;
        }
    }
    cout << "not found";
    return 0;
    // cout << minx << " " << miny << " " << v[miny][minx];
}
