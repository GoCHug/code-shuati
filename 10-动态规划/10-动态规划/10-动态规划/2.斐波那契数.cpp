#include <iostream>

using namespace std;

/*
1.dp[i]的定义为：下标第i个数的斐波那契数值是dp[i]
2.状态转移方程 dp[i] = dp[i - 1] + dp[i - 2];
3.dp数组初始化 dp[0] = 0;dp[1] = 1;
4.确定遍历顺序
5.举例推导dp数组
*/

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            cout  << "dp[" << i - 2 << "] = " << dp[0] << " dp[" << i - 1 << "] = " << dp[1] << " dp["<< i << "] = " << sum << endl;
            dp[0] = dp[1];
            dp[1] = sum;

        }
        return dp[1];

    }
};

int main() {
    int n = 8;

    Solution so;
    int res = so.fib(n);
    cout << "dp[" << n << "] = " << res;
    return 0;
}