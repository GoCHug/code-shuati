#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) result = count;// 取区间累计的最大值（相当于不断确定最大子序终止位置）
            if (count < 0) count = 0;// 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};

int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    Solution so;
    int res = so.maxSubArray(nums);

    cout << res;
    return 0;
}