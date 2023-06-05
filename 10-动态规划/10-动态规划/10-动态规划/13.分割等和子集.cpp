#include <iostream>
#include <vector>
using namespace std;

/*
这道题目是要找是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
那么只要找到集合里能够出现 sum / 2 的子集总和，就算是可以分割成两个相同元素和子集了。

只有确定了如下四点，才能把01背包问题套到本题上来。

背包的体积为sum / 2
背包要放入的商品（集合里的元素）重量为元素的数值，价值也为元素的数值
背包如果正好装满，说明找到了总和为 sum / 2 的子集。
背包中每一个元素是不可重复放入。
以上分析完，我们就可以套用01背包，来解决这个问题了。

1.dp[i]的定义为：
01背包中，dp[j] 表示： 容量为j的背包，所背的物品价值最大可以为dp[j]。
本题中每一个元素的数值既是重量，也是价值。
套到本题，dp[j]表示 背包总容量（所能装的总重量）是j，放进物品后，背的最大重量为dp[j]。
那么如果背包容量为target， dp[target]就是装满 背包之后的重量，所以 当 dp[target] == target 的时候，背包就装满了。
2.状态转移方程：
01背包的递推公式为：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
本题，相当于背包里放入数值，那么物品i的重量是nums[i]，其价值也是nums[i]。
所以递推公式：dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
3.dp数组初始化：
从dp[j]的定义来看，首先dp[0]一定是0。
如果题目给的价值都是正整数那么非0下标都初始化为0就可以了，如果题目给的价值有负数，那么非0下标就要初始化为负无穷。
这样才能让dp数组在递推的过程中取得最大的价值，而不是被初始值覆盖了。
本题题目中 只包含正整数的非空数组，所以非0下标的元素初始化为0就可以了。
4.确定遍历顺序：
物品遍历的for循环放在外层，遍历背包的for循环放在内层，且内层for循环倒序遍历！
5.举例推导dp数组
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // dp[i]中的i表示背包内总和
        // 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
        // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // 也可以使用库函数一步求和
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2;

        // 开始 01背包
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) { // 每一个元素一定是不可重复放入，所以从大到小遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 集合中的元素正好可以凑成总和target
        if (dp[target] == target) return true;
        return false;
    }
};

int main() {
    vector<int> nums = { 1, 5, 11, 5 };

    Solution so;
    bool res = so.canPartition(nums);
    cout << res;
    return 0;
}