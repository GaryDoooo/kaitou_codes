#include <iostream>
using namespace std;
int a[100005];

bool cmp (int a, int b){
    return a > b;
}

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
for (int i=1;i<=n;i++) cout<<a[i]<<endl;
    int maxn = -1;
    int maxt;
    for (int i = 1; i <= n; i++){
        int t = k;
        int s = 0;
        int l = i, r = i;
        while (t > 0){
	   // cout<<t<<" "<<l<<" "<<r<<" "<<i<<endl;
            if (r == n and l == 1){
                break;
            }
            
            
            if (((a[l-1] - a[i]) < (a[i] - a[r+1])) or r == n){
                if (t < (a[l-1]-a[i])){
                break;}
                if (l-1 > 0){
                    t -= a[l-1]-a[i];
                    l--;
                    s++;
                }
            }else{
                if (t < (a[i] - a[r+1]) or r==n) break;
                if (r + 1 <= n){
                    t -= a[i] - a[r+1];
                    r++;
                    s++;
                }
            }
        }
        if (s > maxn){
            maxn = s;
            maxt = a[i];
        }
    }
    cout << maxt << " " << maxn;
    return 0;
}
