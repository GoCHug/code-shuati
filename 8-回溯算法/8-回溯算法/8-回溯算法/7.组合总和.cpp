#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//private:
//    vector<vector<int>> result;
//    vector<int> path;//ȫ�ֱ���Ҳ���Էŵ��ݹ�����ʹ�����õķ�ʽ
//    void backtracking(vector<int>& candidates, int target, int startindex, int sum) {
//        if (sum == target) {
//            result.push_back(path);
//            return;
//        }
//        else if (sum > target) {
//            return;
//        }
//        for (int i = startindex; i < candidates.size(); i++) {
//            sum += candidates[i];
//            path.push_back(candidates[i]);
//            backtracking(candidates, target, i, sum);
//            sum -= candidates[i];
//            path.pop_back();
//        }
//    }
//
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        result.clear(); // ���Բ���
//        path.clear();   // ���Բ���
//        backtracking(candidates, target, 0, 0);
//        return result;
//    }
//};

//��֦
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // ��� sum + candidates[i] > target ����ֹ����
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // ��Ҫ����
        backtracking(candidates, target, 0, 0);
        return result;
    }
};


int main() {
    vector<int> candidates = { 2, 3, 6, 7 };
    int target = 7;

    Solution so;
    vector<vector<int>> res = so.combinationSum(candidates, target);

    for (vector<int>& vec : res) {
        for (int& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}