#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//private:
//    vector<vector<int>> result;
//    vector<int> path;//全局变量也可以放到递归参数里，使用引用的方式
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
//        result.clear(); // 可以不加
//        path.clear();   // 可以不加
//        backtracking(candidates, target, 0, 0);
//        return result;
//    }
//};

//剪枝
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // 如果 sum + candidates[i] > target 就终止遍历
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
        sort(candidates.begin(), candidates.end()); // 需要排序
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