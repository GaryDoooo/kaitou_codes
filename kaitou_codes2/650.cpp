#include <iostream>
using namespace std;
int a[55], f[55];
int main()
{
    int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
	f[1] = a[1];
	for(int i = 2; i <= n; i++){
		f[i] = max(f[i-1], f[i-2] + a[i]);
		ans = max(ans, f[i]);
	}
	cout << ans;
	return 0;
}