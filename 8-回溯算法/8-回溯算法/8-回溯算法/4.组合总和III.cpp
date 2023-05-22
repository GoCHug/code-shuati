#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;//全局变量也可以放到递归参数里，使用引用的方式
    void backtracking(int k, int n, int startindex, int sum) {
        if (path.size() == k) {
            if (sum == n) {
                result.push_back(path);
            }
            return;
        }

        for (int i = startindex; i <= 9 - (k - path.size()) + 1; i++) {
            sum += i;
            path.push_back(i);
            backtracking(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不加
        path.clear();   // 可以不加
        backtracking(k, n, 1, 0);
        return result;
    }
};

int main() {
    int k = 3;
    int n = 9;
    Solution so;
    vector<vector<int>> res = so.combinationSum3(k, n);

    for (vector<int>& vec : res) {
        for (int& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}