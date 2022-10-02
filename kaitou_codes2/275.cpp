#include <iostream>
#include <algorithm>
using namespace std;
int a[105], f[105], g[105];
int n;

// int rec(int m, int i){
//     if (m > n) return 0;
//     if (a[m] > a[i]) return 1 + rec(m+1, i);
    
//     if (m == i) return rec(m+1, i);
//     if (m < i){
//         // if(a[m] < a[m+1]){
//         //     return min(rec(m+1, i), rec(m+2, i)+1);
//         // }
//         int t = 1;
//         while (a[m+t] <= a[m] and m+t < i) t++;
//         return rec(m+t, i) + t-1;
//     }

//     // if (a[m] > a[m+1]){
//     //     return min(rec(m+1, i), rec(m+2, i)+1);
//     // }
//     int t = 1;
//     while (a[m+t] >= a[m] and m+t < n) t++;
//     return rec(m+t, i) + t-1;
// }

// int rec(int i){
    
// }

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 1e9;
    // for (int i = 1; i <= n; i++){
    //     // for (int s = 1; s <= i; s++){
    //     //     ans = min(ans, rec(s, i) + s-1);
    //     // }
        
    // }

    for (int i = 1; i <= n; i++){
        int m = 1e9;
        for (int j = 0; j < i; j++){
            if (a[j] < a[i])
                m = min(m, f[j]+(i-j-1));
        }
        f[i] = m;
    }

    
    int ar[105];
    for (int i = 1; i <= n; i++) {
        ar[i] = a[n-i+1];
    }
    ar[0] = 0;
    // for (int i = 1; i <= n; i++) cout << ar[i] << endl;
    for (int i = 1; i <= n; i++){
        int m = 1e9;
        for (int j = 0; j < i; j++){
            if (ar[j] < ar[i])
                m = min(m, g[j]+(i-j-1));
        }
        g[i] = m;
    }
    for (int i = 1; i <= n; i++){
        ans = min(ans, f[i] + g[n-i+1]);
    }
    // for (int i = 1; i <= n; i++){
    //     cout<< f[i]<<" "<<g[i]<< endl;
    // }
    cout << ans;
    return 0;
}