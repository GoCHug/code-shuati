#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // ��� sum + candidates[i] > target ����ֹ����
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true��˵��ͬһ��֦candidates[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����candidates[i - 1]ʹ�ù�
            // Ҫ��ͬһ����ʹ�ù���Ԫ�ؽ�������
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        result.clear(); // ���Բ���
        path.clear();   // ���Բ���

        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};

int main() {
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;

    Solution so;
    vector<vector<int>> res = so.combinationSum2(candidates, target);

    for (vector<int>& vec : res) {
        for (int& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}