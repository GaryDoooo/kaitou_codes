// generate "10101" for all 0 and 1 combinations
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// void dfs(string result, int n) {
//     if (n == 0) {
//         cout << result << endl;
//         return;
//         //process result.
//     }
//     char c[2] = {'0', '1'};
//     //enumerate all possible options
//     for (int i = 0; i < 2; i++) {
//         string temp = result + c[i];
//         dfs(temp, n - 1);
//     }
// }
//
// int main() {
//     string result = "";
//     dfs(result, 4);
// }
//
// generate 1,2,3,4 all permutations in vector<vector<int>> as result

void dfs(vector<int> v, vector<vector<int>> &res) {
    if (v.size() == 4) {
        //if (find(res.begin(), res.end(), v) == res.end())
        res.push_back(v);
        return;
    }
    for (int i = 1; i <= 4; i++) {
        if (find(v.begin(), v.end(), i) == v.end()) {
            vector<int> temp(v);
            temp.push_back(i);
            dfs(temp, res);
        }
    }
}

int main() {
    vector<vector<int>> result;
    dfs({}, result);
    for (auto i : result) {
        for (auto j : i) cout << j;
        cout << ", ";
    }
}
