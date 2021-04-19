#include <iostream>
#include <vector>
#include <algorithm>

#define vi vector<int>
using namespace std;

int bsearch (vi l, int n){
	sort(l.begin(), l.end());
	int right = l.size();
	int left = 0;
	int ans;
	for (int i = 0; i < l.size(); i++){
		ans = (right+left) / 2;
		if (l[ans] == n) return ans;
		if (n > l[ans] ) left = ans+1;
		else  right = ans;
	}
	return -1;
}
int main(){
	vi a = {3, 6, 7, 999, 43, 8, 0, -1};
	int e = bsearch(a, 99);
	cout << e;
}
