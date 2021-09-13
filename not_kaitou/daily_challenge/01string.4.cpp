#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[100], t, n;
int check(int k) {
    for (int i = 1; i <= k / 3;
            i++) { //若长度为k,则分成 3份，每份的长度为总长k/3，这就是长度最长的子串。
        int flag = 1;
        for (int L = 1; L <= i;
                L++) //搜索增量L为1~i ，例如:check(3),check(4),check(5)，分别会检查1,2,3和2 ,3,4和3,4,5 对于6呢，既要检查
//4,5,6，又要检查1 3 5,若135相同还要检查2,4,6，否则中止检查
            if (num[k - 3 * i + L] != num[k - 3 * i + L + i]
                    || num[k - 3 * i + L] != num[k - 3 * i + L + i + i]) //这个表达式是本题的难点,同学们记住第一个就行了,后面
//的两个数就好理解了,一个加i，另一个加i*2
            {
                flag = 0; //表明没有三个连续的子串
                break; //无需判断内循环后面的情况，例如检查了147不合，无需检查258，跳出内循环，继续外循环
            }
        if (flag) { return 0;} //有三个连续的子串，就终止，返回0。
    }
    return 1; //没有三个连续的子串就返回1
}
void dfs(int step) {
    if (step > n) {
        t++;
        return ;
    }
    for (int i = 0; i <= 1; i++) {
        num[step] = i;
        if (check(
                    step)) //检查整个串，若得到到返回值1（即表明在当前长度为step的串中没有三个连续的子串，
//就进入递归下一轮dfs,即:在当前字符串(num数组)再增加一个0/1字符，接着再去检查整个串，如此循环直到长度大于n，则计数
//器加1，如果返回值为0，就扔了刚增加的这个字符，换另一个字符）
            dfs(step + 1);
    }
}
int main() {
//freopen("d:\\out.txt","w",stdout);
    scanf("%d", &n);
    num[1] = 0;
    dfs(2); //用户输入为1和2都是执行dfs(2)
    printf("%d\n", t * 2);
    /*这个t值要乘以2，因为dfs(2)赋值是从2开始，dfs函数并未对num[1]赋值0和1(初始化时为0， 1的情况没有处理)，所以答案要*2
    或者你把上面的改成以下也可以。
    num[1]=0;
    dfs(2);
    num[1]=1;
    dfs(2);
    */
    return 0;
}