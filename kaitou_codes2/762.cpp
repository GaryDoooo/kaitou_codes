#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    sort(a+1, a+n+1);
    int l, u;
    long long ans = 0;
    for (int i = 1; i < n; i++){
        int t = x - a[i];
        l = lower_bound(a+i+1, a+n+1, t) - a;
        u = upper_bound(a+i+1, a+n+1, t) - a;
        ans += u - l;
    }
    cout << ans;
}