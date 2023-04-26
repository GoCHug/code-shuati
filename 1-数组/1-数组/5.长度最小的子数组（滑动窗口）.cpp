#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    ////暴力解法 O(n^2) 力扣超时
    //int minSubArrayLen(int s, vector<int>& nums) {
    //    int res = INT_MAX;
    //    int subLen = 0;
    //    for (int i = 0; i < nums.size(); ++i) {
    //        int sum = 0;
    //        for (int j = i; j < nums.size(); ++j) {
    //            sum += nums[j];
    //            if (sum >= s) {
    //                subLen = j - i + 1;
    //                res = min(res, subLen);
    //                break;//找到以i开头长度最小的子数组后break
    //            }
    //        }
    //    }
    //    return res == INT_MAX ? 0 : res;
    //}

    //滑动窗口 O(n)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left++];//不断滑动窗口左侧
            }
        }
        return res == INT_MAX ? 0 : res;
    }

};

int main() {
    Solution s;
    int n = 7;
    vector<int> nums = { 2,3,1,2,4,3 };
    int res = s.minSubArrayLen(n, nums);

    cout << res;

    return 0;
}