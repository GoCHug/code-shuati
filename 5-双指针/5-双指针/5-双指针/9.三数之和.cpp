#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) return res;
            //对a去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //再找到一个三元组后，对b,c去重
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    //找到答案了，双指针移动
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> num = { -1,0,1,2,-1,-4 };

    Solution so;
    vector<vector<int>> res = so.threeSum(num);
    for (auto& v : res) {
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

