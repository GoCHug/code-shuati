#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    // n Ϊ��������̴�С
    // row �ǵ�ǰ�ݹ鵽���̵ĵڼ�����
    void backtracking(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)) { // ��֤�Ϸ��Ϳ��Է�
                chessboard[row][col] = 'Q'; // ���ûʺ�
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.'; // ���ݣ������ʺ�
            }
        }
    }
    bool isValid(int row, int col, vector<string>& chessboard, int n) {
        //��Ϊ�ڵ��������Ĺ����У�ÿһ��ݹ飬ֻ��ѡforѭ����Ҳ����ͬһ�У����һ��Ԫ�أ����Բ���ȥ���ˡ�
        // �����
        for (int i = 0; i < row; i++) { // ����һ����֦
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // ��� 45�Ƚ��Ƿ��лʺ�
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // ��� 135�Ƚ��Ƿ��лʺ�
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main() {
    int n = 4;

    Solution so;
    vector<vector<string>> res = so.solveNQueens(n);

    for (vector<string>& vec : res) {
        for (auto& s : vec) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}