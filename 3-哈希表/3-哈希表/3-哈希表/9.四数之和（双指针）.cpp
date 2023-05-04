#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // ��֦����
            if (nums[k] > target && nums[k] >= 0) {
                break; // ����ʹ��break��ͳһͨ������return����
            }
            // ��nums[k]ȥ��
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2����֦����
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }

                // ��nums[i]ȥ��
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target �����
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                        // nums[k] + nums[i] + nums[left] + nums[right] < target �����
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // ��nums[left]��nums[right]ȥ��
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // �ҵ���ʱ��˫ָ��ͬʱ����
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
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