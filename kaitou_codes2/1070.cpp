#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int v[2005];
long long f[5005];

int main(){
    int t, m;
    cin >> m >> t;
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }
	f[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = v[i]; j <= t; j++){   
            f[j] = f[j] + f[j-v[i]];
        }
    }
    cout << f[t];
    return 0;
}