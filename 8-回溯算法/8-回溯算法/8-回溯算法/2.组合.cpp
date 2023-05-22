#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;//ȫ�ֱ���Ҳ���Էŵ��ݹ�����ʹ�����õķ�ʽ
    void backtracking(int n, int k, int startindex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = startindex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // ���Բ�д
        path.clear();   // ���Բ�д
        backtracking(n, k, 1);
        return result;
    }
};

int main() {
    int n = 4;
    int k = 2;
    Solution so;
    vector<vector<int>> res = so.combine(n, k);

    for (vector<int>& vec : res) {
        for (int& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}