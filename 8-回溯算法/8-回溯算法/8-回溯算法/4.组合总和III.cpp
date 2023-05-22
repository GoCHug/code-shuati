#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;//ȫ�ֱ���Ҳ���Էŵ��ݹ�����ʹ�����õķ�ʽ
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
        result.clear(); // ���Բ���
        path.clear();   // ���Բ���
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