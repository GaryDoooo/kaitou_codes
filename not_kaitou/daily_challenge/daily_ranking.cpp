#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second or (a.second == b.second) and (a.first < b.first);
}
int main() {
    map<string, int> score;
    int rank_score[205] = {5, 3, 1, 1, 1};
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            score[s] += rank_score[j];
        }
    }
    vector<pair<string, int>> sort_temp;
    for (auto it = score.begin(); it != score.end(); it++) sort_temp.push_back(make_pair(it->first, it->second));
    sort(sort_temp.begin(), sort_temp.end(), cmp);
    for (auto it = sort_temp.begin(); it != sort_temp.end(); it++) {
        if (it->second == 0) break;
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}