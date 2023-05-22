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
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path); // �ռ��Ӽ���Ҫ������ֹ��ӵ����棬�����©���Լ�
        if (startIndex >= nums.size()) { // ��ֹ�������Բ���
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main() {
    vector<int> nums = { 1, 2, 3 };

    Solution so;
    vector<vector<int>> res = so.subsets(nums);

    for (vector<int>& vec : res) {
        for (int& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}