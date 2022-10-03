#include <bits/stdc++.h>
using namespace std;
int n, k, a, b, res;
vector<pair<int, int>> movies;  // first is end, second is start
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        movies.push_back(make_pair(b, a));
    }
    if (n <= k) {
        cout << n;
        return 0;
    }
    sort(movies.begin(), movies.end());
    multiset<pair<int, int>> person;
    for (int i = 0; i < k; i++) person.insert(make_pair(0, 0));
    // res = k;
    for (int i = 0; i < n; i++) {
        auto it = person.lower_bound(make_pair(movies[i].second, 0));
        if (it == person.begin())
            if (movies[i].second < it->first) continue;
        if (it == person.end() or it->first > movies[i].second) it--;
        person.erase(it);
        person.insert(movies[i]);
        res++;
    }
    cout << res << endl;
}

