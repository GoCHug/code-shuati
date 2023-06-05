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

1.dp数组定义为：
dp[j]表示容量（这里说容量更形象，其实就是重量）为j的背包，最多可以背最大重量为dp[j]。
可以回忆一下01背包中，dp[j]的含义，容量为j的背包，最多可以装的价值为 dp[j]。
相对于 01背包，本题中，石头的重量是 stones[i]，石头的价值也是 stones[i] ，
可以 “最多可以装的价值为 dp[j]” == “最多可以背的重量为dp[j]”
2.状态转移方程：
01背包的递推公式为：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
本题则是：dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
3.dp数组初始化：
既然 dp[j]中的j表示容量，那么最大容量（重量）是多少呢，就是所有石头的重量和。
因为提示中给出1 <= stones.length <= 30，1 <= stones[i] <= 1000，所以最大重量就是30 * 1000 。
而我们要求的target其实只是最大重量的一半，所以dp数组开到15000大小就可以了。
当然也可以把石头遍历一遍，计算出石头总重量 然后除2，得到dp数组的大小。
我这里就直接用15000了。
接下来就是如何初始化dp[j]呢，因为重量都不会是负数，所以dp[j]都初始化为0就可以了，
这样在递归公式dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);中dp[j]才不会初始值所覆盖。
4.确定遍历顺序：
如果使用一维dp数组，物品遍历的for循环放在外层，遍历背包的for循环放在内层，且内层for循环倒序遍历！
5.举例推导dp数组
最后dp[target]里是容量为target的背包所能背的最大重量。
那么分成两堆石头，一堆石头的总重量是dp[target]，另一堆就是sum - dp[target]。
在计算target的时候，target = sum / 2 因为是向下取整，所以sum - dp[target] 一定是大于等于dp[target]的。
那么相撞之后剩下的最小石头重量就是 (sum - dp[target]) - dp[target]。
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) sum += stones[i];
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) { // 遍历物品
            for (int j = target; j >= stones[i]; j--) { // 遍历背包
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

int main() {
    vector<int> stones = { 31,26,33,21,40 };

    Solution so;
    int res = so.lastStoneWeightII(stones);
    cout << res;
    return 0;
}