#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) return res;// 若 nums 长度小于 4，直接返回空结果，不判断下边nums.size() - 3会报错内存越界
        for (int k = 0; k < nums.size() - 3; k++) {
            if (nums[k] > target && nums[k] >= 0) break;//剪枝
            //对a去重
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            for (int i = k + 1; i < nums.size() - 2; i++) {
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) break;//剪枝
                //对b去重
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;//！！注意对b去重时候i > k + 1
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
                    else if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
                    else {
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        //对c、d去重
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        //压入res后移动指针要在去重之后
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> num = { 1,0,-1,0,-2,2 };
    int target = 0;
    Solution so;
    vector<vector<int>> res = so.fourSum(num, target);
    for (auto& v : res) {
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}