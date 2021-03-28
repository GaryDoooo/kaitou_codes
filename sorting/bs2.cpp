#include <iostream>
#include <vector>
#include <algorithm>

#define vi vector<int>
using namespace std;

int bsearch (vi l, int n){
	sort(l.begin(), l.end());
	int right = l.size();
	int k = 0;
	int ans;
	for (int b = right/2;  b >=1; b/=2){
		//while (k+b<l.size() and l[k+b]<=n) {
		if (l[k+b]<=n){
			k+=b;
			cout <<k <<endl;
		}
	}
	if (l[k]==n)
		return k;
	else
		return -1;
}
int main(){
	vi a = {3, 6, 7, 999, 43, 8, 0, -1};
	int e = bsearch(a,999);
	cout << e;
}
