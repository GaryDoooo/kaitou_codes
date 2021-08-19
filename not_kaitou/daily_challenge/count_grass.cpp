#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w, res = 0, index = 0;
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
        while (todo.size() > 0) {
            int n = todo.top(); todo.pop();
            photo[n] = '.';
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
    }
    cout << res << endl;
    return 0;
}