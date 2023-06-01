#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]的定义为：爬到第i层楼梯，有dp[i]种方法
2.状态转移方程：
从dp[i]的定义可以看出，dp[i] 可以有两个方向推出来。
首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，那么再一步跳一个台阶不就是dp[i]了么。
还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，那么再一步跳两个台阶不就是dp[i]了么。
那么dp[i]就是 dp[i - 1]与dp[i - 2]之和！
所以dp[i] = dp[i - 1] + dp[i - 2] 。
3.dp数组初始化：
爬到第一层楼梯有一种方法，爬到二层楼梯有两种方法。
不考虑dp[0]如何初始化，只初始化dp[1] = 1，dp[2] = 2，然后从i = 3开始递推，这样才符合dp[i]的定义。
4.确定遍历顺序：
从递推公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，遍历顺序一定是从前向后遍历的
5.举例推导dp数组
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }

    ////优化空间的版本
    ////但我个人认为面试中能写出版本一就够了哈，清晰明了，如果面试官要求进一步优化空间的话，我们再去优化。
    //int climbStairs(int n) {
    //    if (n <= 2) return n;
    //    vector<int> dp(3);
    //    dp[1] = 1;
    //    dp[2] = 2;
    //    for (int i = 3; i <= n; i++) {
    //        int sum = dp[1] + dp[2];
    //        dp[1] = dp[2];
    //        dp[2] = sum;
    //    }
    //    return dp[2];
    //}

};

int main() {
    int n = 8;

    Solution so;
    int res = so.climbStairs(n);
    cout << "dp[" << n << "] = " << res;
    return 0;
}