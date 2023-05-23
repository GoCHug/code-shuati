#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//�Ӽ����ռ����νṹ���������нڵ�Ľ��
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        result.push_back(path); // �ռ��Ӽ���Ҫ������ֹ��ӵ����棬�����©���Լ�
        if (startIndex >= nums.size()) { // ��ֹ�������Բ���
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // ȥ����Ҫ����
        backtracking(nums, 0, used);
        return result;
    }
};

int main() {
    vector<int> nums = { 1, 2, 2 };

    Solution so;
    vector<vector<int>> res = so.subsetsWithDup(nums);

    for (vector<int>& vec : res) {
        for (int& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}