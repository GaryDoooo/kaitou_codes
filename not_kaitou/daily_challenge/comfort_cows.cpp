#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> cord;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};
typedef unordered_set<cord, pair_hash> cset;
cset cows;
cset new_cows;
cset comfort_cows;
int dx[] = {0, 0, 1, -1}, dy[] = { -1, 1, 0, 0};
cord find_cord(cord &xy) {
    cord new_xy;
    for (int i = 0; i < 4; i++) {
        new_xy.first = xy.first + dx[i];
        new_xy.second = xy.second + dy[i];
        if (cows.find(new_xy) == cows.end() and new_cows.find(new_xy) == new_cows.end())
            return new_xy;
    }
}
void check_comfort(cord &xy, bool root) {
    cord new_xy;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        new_xy.first = xy.first + dx[i];
        new_xy.second = xy.second + dy[i];
        if (cows.find(new_xy) != cows.end() or new_cows.find(new_xy) != new_cows.end()) {
            cnt++;
            if (root) check_comfort(new_xy, false);
        }
    }
    if (cnt == 3) comfort_cows.insert(xy);
}
void add_cow(cord &xy) {
    new_cows.erase(xy); cows.insert(xy);
    check_comfort(xy, true);
}
void add_new_cow(cord &xy) {
    if (cows.find(xy) == cows.end()) new_cows.insert(xy);
    check_comfort(xy, true);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cord xy;
        cin >> xy.first >> xy.second;
        cows.insert(xy);
        add_cow(xy);
        // cout << "comfort_cows" << comfort_cows.size() <<	endl; //>>
        while (comfort_cows.size() > 0) {
            cset temp(comfort_cows.begin(), comfort_cows.end());
            for (cord xy : temp) {
                cord new_cow = find_cord(xy);
                add_new_cow(new_cow);
                comfort_cows.erase(xy);
            }
        }
        cout << new_cows.size() << endl;
    }
    return 0;
}