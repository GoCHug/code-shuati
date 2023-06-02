#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]的定义为：dp[i]：拆分数字i，可以得到的最大乘积为dp[i]。
2.状态转移方程：
j从1遍历到i，j * (i - j) 是单纯的把整数拆分为两个数相乘，
而j * dp[i - j]是拆分成两个以及两个以上的个数相乘。
dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j});
那么在取最大值的时候，为什么还要比较dp[i]呢？
因为在递推公式推导的过程中，每次计算dp[i]，取最大的而已。
3.dp数组初始化：
从dp[i]的定义来说，dp[0] dp[1] 就不应该初始化，也就是没有意义的数值。
这里我只初始化dp[2] = 1，从dp[i]的定义来说，拆分数字2，得到的最大乘积是1，这个没有任何异议！
4.确定遍历顺序：
dp[i] 是依靠 dp[i - j]的状态，所以遍历i一定是从前向后遍历，先有dp[i - j]再有dp[i]。
5.举例推导dp数组
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));//比较dp[i]是因为固定了i，j在变，更新不同j下的dp[i]
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 7;

    Solution so;
    int res = so.integerBreak(n);
    cout << "dp[" <<  n << "]= " << res;
    return 0;
}