#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]的定义为：在一维dp数组中，dp[j]表示：容量为j的背包，所背的物品价值可以最大为dp[j]。
2.状态转移方程：
dp[j]为 容量为j的背包所背的最大价值，那么如何推导dp[j]呢？
dp[j]可以通过dp[j - weight[i]]推导出来，dp[j - weight[i]]表示容量为j - weight[i]的背包所背的最大价值。
dp[j - weight[i]] + value[i] 表示容量为 j - 物品i重量的背包 加上 物品i的价值。
（也就是容量为j的背包，放入物品i了之后的价值即：dp[j]）
此时dp[j]有两个选择，一个是取自己dp[j] 相当于 二维dp数组中的dp[i-1][j]，即不放物品i，
一个是取dp[j - weight[i]] + value[i]，即放物品i，指定是取最大的，毕竟是求最大价值，
所以递归公式为：
dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
可以看出相对于二维dp数组的写法，就是把dp[i][j]中i的维度去掉了。
3.dp数组初始化：
关于初始化，一定要和dp数组的定义吻合，否则到递推公式的时候就会越来越乱。
dp[j]表示：容量为j的背包，所背的物品价值可以最大为dp[j]，那么dp[0]就应该是0，因为背包容量为0所背的物品的最大价值就是0。
那么dp数组除了下标0的位置，初始为0，其他下标应该初始化多少呢？
看一下递归公式：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
dp数组在推导的时候一定是取价值最大的数，如果题目给的价值都是正整数那么非0下标都初始化为0就可以了。
这样才能让dp数组在递归公式的过程中取的最大的价值，而不是被初始值覆盖了。
那么我假设物品价值都是大于0的，所以dp数组初始化的时候，都初始为0就可以了。
4.确定遍历顺序：
倒序遍历的原因是，本质上还是一个对二维数组的遍历，并且右下角的值依赖上一层左上角的值，
因此需要保证左边的值仍然是上一层的，从右向左覆盖。
for(int i = 0; i < weight.size(); i++) { // 遍历物品
    for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}

5.举例推导dp数组
*/

void test_1_wei_bag_problem() {
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

int main() {
    test_1_wei_bag_problem();
}
