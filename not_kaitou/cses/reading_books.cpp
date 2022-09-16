#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, t[212345];
ll res,sum;
ll get_time(ll total, int i){
    if (i<0) return 0;
    if(( t[i]<<1)>=total) return t[i]<<1;
    return t[i]+get_time(total-
int main() {
    cin >>n;
    for (int i=0; i<n; i++) {cin >>t[i];sum+=t[i];}
    sort(t,t+n);
    cout << get_time(sum,n-1) << endl;
}


