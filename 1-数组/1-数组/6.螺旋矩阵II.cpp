#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int loop = n / 2;//��Ҫѭ����Ȧ�� 3/2=1Ȧ �����Ļ��м��Ԫ�ص�������  4/2=2Ȧ
        int count = 1;//������ֵ��Ԫ��
        int startx = 0, starty = 0;//ÿһȦѭ������ʼλ��
        int offset = 1;//����ÿһ���߱����ĳ���

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
            starty++;//��һȦ����1
            offset++;//����ÿһȦ�߱����ĳ���
        }
        if (n % 2) {//�����Ļ�����Ҫ�����м䵥����ֵ
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