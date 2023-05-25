#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
private:
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {        // ������
            for (int j = 0; j < board[0].size(); j++) { // ������
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {     // (i, j) ���λ�÷�k�Ƿ����
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;                // ����k
                            if (backtracking(board)) return true; // ����ҵ�����һ�����̷���
                            board[i][j] = '.';              // ���ݣ�����k
                        }
                    }
                    return false;  // 9�����������ˣ������У���ô�ͷ���false
                }
            }
        }
        return true; // ������û�з���false��˵���ҵ��˺�������λ����
    }
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) { // �ж������Ƿ��ظ�
            if (board[row][i] == val) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) { // �ж������Ƿ��ظ�
            if (board[j][col] == val) {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // �ж�9�������Ƿ��ظ�
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main() {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                    {'8', '.', '.', '.', '6', '.', '.', '.', '3' },
                                    {'4', '.', '.', '8', '.', '3', '.', '.', '1' },
                                    {'7', '.', '.', '.', '2', '.', '.', '.', '6' },
                                    {'.', '6', '.', '.', '.', '.', '2', '8', '.' },
                                    {'.', '.', '.', '4', '1', '9', '.', '.', '5' },
                                    {'.', '.', '.', '.', '8', '.', '.', '7', '9' } };

    Solution so;
    so.solveSudoku(board);

    for (vector<char>& vec : board) {
        for (auto& c : vec) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}