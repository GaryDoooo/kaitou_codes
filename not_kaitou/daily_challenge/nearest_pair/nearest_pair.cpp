#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int d[n + 1][n + 1], ui, vi, wi; //d记录每两个点之间的最短距离
    memset(d, 1, sizeof(d));
    // 把数组里面每个数字设置成0x01010101也就是16843009，反正是个很大的数就可以
    for (int i = 1; i <= n; i++) {d[i][i] = 0;} //每个点到自己的距离是0
    for (int i = 1; i < n; i++) {
        cin >> ui >> vi >> wi; //读取一条新的边 uv
        for (int j = 1; j <= n; j++)
            if (j != ui and d[j][vi] < 1001)
                //遍历每一个点j，如果从ui到vi再到j的距离小于已有的ui到j的距离，就用小的距离替换
                //当然，如果j和ui是一个点，或者j和vi并不项链就跳过。
                //但是j可以等于vi，vi到自己的距离等于零，就相当于给ui到vi的距离赋值wi了
                d[j][ui] = d[ui][j] = min(d[j][ui], d[j][vi] + wi);
        for (int j = 1; j <= n; j++) if (j != vi and d[j][ui] < 1001) d[j][vi] = d[vi][j] = min(d[j][vi], d[j][ui] + wi);
        //同一事情再重复，遍历每一个点j，如果从vi到ui再到j的距离小于已有的vi到j的距离，就用小的距离替换
    }
    cout << *min_element((int *)d, (int *)d + sizeof(d) / sizeof(int));
    //最后输出数组里面最小的数字，这里每道题都应该有负数距离，所以没有问题。如果距离都是正的，就会出错。
    return 0;
}