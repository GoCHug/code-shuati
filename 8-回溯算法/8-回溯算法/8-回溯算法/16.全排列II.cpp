#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        // ��ʱ˵���ҵ���һ��
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true��˵��ͬһ��֦nums[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����nums[i - 1]ʹ�ù�
            // ���ͬһ����nums[i - 1]ʹ�ù���ֱ������
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // ����
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
int main() {
    vector<int> nums = { 1,2,1 };

    Solution so;
    vector<vector<int>> res = so.permuteUnique(nums);

    for (vector<int>& vec : res) {
        for (int& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}