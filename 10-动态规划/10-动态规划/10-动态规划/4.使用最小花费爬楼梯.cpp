#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]的定义为：到达第i台阶所花费的最少体力为dp[i]。
2.状态转移方程：
可以有两个途径得到dp[i]，一个是dp[i-1] 一个是dp[i-2]。
dp[i - 1] 跳到 dp[i] 需要花费 dp[i - 1] + cost[i - 1]。
dp[i - 2] 跳到 dp[i] 需要花费 dp[i - 2] + cost[i - 2]。
那么究竟是选从dp[i - 1]跳还是从dp[i - 2]跳呢？
一定是选最小的，所以dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
3.dp数组初始化：
题目描述中明确说了 “你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。”
也就是说 到达 第 0 个台阶是不花费的，但从 第0 个台阶 往上跳的话，需要花费 cost[0]。
所以初始化 dp[0] = 0，dp[1] = 0;
4.确定遍历顺序：
因为是模拟台阶，而且dp[i]由dp[i-1]dp[i-2]推出，所以是从前到后遍历cost数组就可以了
5.举例推导dp数组
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[n];
    }
};

int main() {
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };

    Solution so;
    int res = so.minCostClimbingStairs(cost);
    cout << "dp[" << cost.size() << "] = " << res;
    return 0;
}