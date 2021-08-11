#include<bits/stdc++.h>
using namespace std;
const int B = 5e4 + 20;
int arr[B];
int L, M, N;
bool judge(int x ) {
    int sum = 0; //记录需要移走的石头数
    int i = 0; //下一个石头的编号
    int now = 0; //now代表模拟跳石头的人当前在什么位置
    while (i < N + 1) { //n+1是终点，n不是
        i++;
        if (arr[i] - arr[now] < x) //判断二者的差值与的能跳值的关系
            sum++;//判定成功石头就拿走了，考虑下一块石头
        else
            now = i; //不行的话换下一个石头,这块跳过去
    }
    if (sum > M)
        return false;
    else
        return true;
}
int main() {
    int ans = 0;
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    arr[N + 1] = L; //敲黑板划重点，再强调一遍，n不是终点
    int l = 1, r = L;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (judge(mid)) {
            ans = mid;
            l = mid + 1; //已经有可行解，检查是否有更优解
        } else {
            r = mid - 1; //错了，换方向找找
        }
    }
    cout << ans << endl;
    return 0;
}