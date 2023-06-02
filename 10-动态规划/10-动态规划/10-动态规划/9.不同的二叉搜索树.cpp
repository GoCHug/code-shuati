#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]的定义为：dp[i] ： 1到i为节点组成的二叉搜索树的个数为dp[i]。
也可以理解是i个不同元素节点组成的二叉搜索树的个数为dp[i] ，都是一样的。
2.状态转移方程：
dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]
j相当于是头结点的元素，从1遍历到i为止。
所以递推公式：dp[i] += dp[j - 1] * dp[i - j]; ，j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量
3.dp数组初始化：
定义上来讲，空节点也是一棵二叉树，也是一棵二叉搜索树，这是可以说得通的。
初始化dp[0] = 1
4.确定遍历顺序：
首先一定是遍历节点数，从递归公式：dp[i] += dp[j - 1] * dp[i - j]可以看出，节点数为i的状态是依靠 i之前节点数的状态。
那么遍历i里面每一个数作为头结点的状态，用j来遍历。
5.举例推导dp数组
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 7;

    Solution so;
    int res = so.numTrees(n);
    cout << "dp[" << n << "]= " << res;
    return 0;
}