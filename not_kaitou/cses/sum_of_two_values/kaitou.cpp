#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, x;
struct Val{
    int v, i;
};
bool cmp(Val a, Val b){
    return (a.v < b.v);
}
vector<Val> a;

int main(){
    scanf("%d %d",&n,&x);
    int t;
    for (int i = 1; i <= n; i++){
        scanf("%d", &t);
        a.push_back((Val){t, i});
    }
    sort(a.begin(), a.end(), cmp);

    int l = 0, r = n-1;
    while (l < r){
        if (a[l].v + a[r].v < x){
            l++;
        }else if (a[l].v + a[r].v > x){
            r--;
        }if (a[l].v + a[r].v == x){
            printf("%d %d\n", a[l].i, a[r].i);
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
