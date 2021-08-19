#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w, res = 0, index = 0, barn = 0;
    cin >> h >> w;
    char photo[h * w];
    string temp;
    for (int i = 0; i < h; i++) {
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) photo[index++] = temp[j];
    }
    for (int i = 0; i < h * w; i++) {
        if (photo[i] != '#') continue;
        res++;
        stack<int> todo;
        todo.push(i);
        set<int> points;
        vector<int> x, y;
        while (todo.size() > 0) {
            int n = todo.top(); todo.pop();
            photo[n] = '.';
            points.insert(n);
            set<int> dir{1, -1, w, -w};
            if (n % w == 0) dir.erase(-1);
            if (n % w == w - 1)dir.erase(1);
            if (n < w)dir.erase(-w);
            if (n >= w * (h - 1))dir.erase(w);
            for (int d : dir) {
                int new_pos = n + d;
                if (photo[new_pos] == '#') todo.push(new_pos);
            }
        }
        for (int point : points) {x.push_back(point % w); y.push_back(point / w); }
        int width = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end()) + 1;
        int height = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end()) + 1;
        // cout << width << " " << height << " " << points.size() << endl;
        // for (int point : points) cout << point << " ";
        // cout << endl;
        barn += (width * height == points.size());
    }
    cout << barn << endl << res - barn << endl;
    return 0;
}