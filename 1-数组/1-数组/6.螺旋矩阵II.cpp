#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int loop = n / 2;//需要循环的圈数 3/2=1圈 奇数的话中间的元素单独处理  4/2=2圈
        int count = 1;//给矩阵赋值的元素
        int startx = 0, starty = 0;//每一圈循环的起始位置
        int offset = 1;//控制每一条边遍历的长度

        while (loop--) {
            int i = startx;
            int j = starty;
            for (j = starty; j < n - offset; ++j) {
                res[startx][j] = count++;
            }
            for (i = startx; i < n - offset; ++i) {
                res[i][j] = count++;
            }
            for (; j > starty; --j) {
                res[i][j] = count++;
            }
            for (; i > startx; --i) {
                res[i][j] = count++;
            }
            startx++;
            starty++;//下一圈起点加1
            offset++;//控制每一圈边遍历的长度
        }
        if (n % 2) {//奇数的话，需要给最中间单独赋值
            int mid = n / 2;
            res[mid][mid] = count;
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 5;
    vector<vector<int>> res = s.generateMatrix(n);

    for (auto i : res) {
        for (auto j : i) {
            printf("%2d ", j);
        }
        cout << endl;
    }
    return 0;
}