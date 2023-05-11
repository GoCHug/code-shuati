#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) return res;// �� nums ����С�� 4��ֱ�ӷ��ؿս�������ж��±�nums.size() - 3�ᱨ���ڴ�Խ��
        for (int k = 0; k < nums.size() - 3; k++) {
            if (nums[k] > target && nums[k] >= 0) break;//��֦
            //��aȥ��
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            for (int i = k + 1; i < nums.size() - 2; i++) {
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) break;//��֦
                //��bȥ��
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;//����ע���bȥ��ʱ��i > k + 1
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
                    else if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
                    else {
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        //��c��dȥ��
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        //ѹ��res���ƶ�ָ��Ҫ��ȥ��֮��
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