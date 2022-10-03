#include <iostream>
#include <cstring>

using namespace std;
int a, f[1000005];
int main()
{
	cin >> a;
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; (i*i*i) <= a; i++) {
		for (int j = 0; j <= a; j++) {
			if(j - (i*i*i) >= 0) {
                f[j] = min(f[j], f[j - (i*i*i)] + 1);
            }
        }
	}
	cout << f[a];
	return 0;
}