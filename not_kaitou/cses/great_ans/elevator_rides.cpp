#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
//把pair定义成一个由第一个变量排序的struct。
int main() {
	int n, c, i, j, t, w, num;
	cin >> n >> c;
	int N = 1<<n; //2**20是一百万
	pii dp[N]; //用N的每一位表示物品选择与否。从0到N的所有数可以表示所有组合
                  // 所以这是一种很好的遍历所有组合的方法。
	for(i = 0; i < n; i++) {
		cin >> num;
		dp[1<<i] = make_pair(1, num); // 只选择单一物品。
	}
	for(dp[0]={1, 0}, i = 1; i < N; i++) {
		if((i & (i-1)) == 0) //IMPORTANT!!! 重要技巧，只有2的整数幂才符合这个条件
			continue;
		dp[i] = {INT_MAX, INT_MAX}; //后面的max赋值与否不重要
		for(j = i; j; j -=(j&-j)) {
                 // IMPORTANT!!!!
                // j&-j 是j的最右一位bit，j=10，结果就是2，j=8，结果就是8
               // 用这样的方法可以快速准确的遍历i里面每一个是1的bit
			w = dp[j&-j].y+dp[i-(j&-j)].y; //从一个组合里面拿掉一个，值一定变小, must be done
			if(w <= c)
				dp[i] = min(dp[i], {dp[i-(j&-j)].x, w});
			else
				dp[i] = min(dp[i], {dp[i-(j&-j)].x+1, dp[j&-j].y});
		}
	}
	cout << dp[N-1].first << endl; //N-1就是包含所有物品的组合，第一个变量就是用几个包裹
}
