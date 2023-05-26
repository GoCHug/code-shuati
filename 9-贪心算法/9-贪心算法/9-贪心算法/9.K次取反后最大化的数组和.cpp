#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//局部最优：让绝对值大的负数变为正数，当前数值达到最大，整体最优：整个数组和达到最大。
//又是一个贪心：局部最优：只找数值最小的正整数进行反转，当前数值和可以达到最大
//（例如正整数数组{5, 3, 1}，反转1 得到-1 比 反转5得到的-5 大多了），全局最优：整个 数组和 达到最大。
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int min_abs = INT_MAX;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            min_abs = min(abs(nums[i]), min_abs);//记录绝对值最小的数
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
            sum += nums[i];
        }

        if (k %= 2) {//此时已经全部是正数了，k还大于0，需要减去最小的正数
            sum -= 2 * min_abs;
        }
        return sum;
    }
};


int main() {
    vector<int> nums = { 3,-1,0,2 };
    int k = 3;

    Solution so;
    int res = so.largestSumAfterKNegations(nums, k);

    cout << res;
    return 0;
}