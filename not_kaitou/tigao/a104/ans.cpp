#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l;
    cin >> l;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e, res = 0;
        cin >> s >> e;
        int step = (e > s ? 1 : -1);
        int t = s, tp = a[s];
        while (1) {
            int next_step = t + step;
            if (abs(a[next_step] - tp) > l) {
                res++;
                tp = a[t];
            } else if (next_step == e) {
                res++;
                break;
            } else {
                t = next_step;
            }
        }
        cout << res << endl;
    }
}

