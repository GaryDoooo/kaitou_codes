#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],f[100005][20];
int main(){
    cin >>n;
    for (int i = 0; i < n;i++) cin>>f[i][0];
    for (int k=1,j=1;k<=n;k<<=1,j++){
        for (int i=0;i+k<n;i++){
            f[i][j]=max(f[i][j-1],

