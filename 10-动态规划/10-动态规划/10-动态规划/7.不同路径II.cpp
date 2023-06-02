#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]�Ķ���Ϊ��dp[i][j] ����ʾ�ӣ�0 ��0����������(i, j) ��dp[i][j]����ͬ��·����
2.״̬ת�Ʒ��̣�
��Ҫ��dp[i][j]��ֻ���������������Ƶ���������dp[i - 1][j] �� dp[i][j - 1]��
��ʱ�ڻع�һ�� dp[i - 1][j] ��ʾɶ���Ǵ�(0, 0)��λ�õ�(i - 1, j)�м���·����dp[i][j - 1]ͬ��
��ô����Ȼ��dp[i][j] = dp[i - 1][j] + dp[i][j - 1]����Ϊdp[i][j]ֻ���������������
��������Ҫע��һ�㣬��Ϊ�����ϰ���(i, j)��������ϰ��Ļ�Ӧ�þͱ��ֳ�ʼ״̬����ʼ״̬Ϊ0����
if (obstacleGrid[i][j] == 0) { // ��(i, j)û���ϰ���ʱ�����Ƶ�dp[i][j]
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
}
3.dp�����ʼ����
��γ�ʼ���أ�����dp[i][0]һ������1����Ϊ��(0, 0)��λ�õ�(i, 0)��·��ֻ��һ������ôdp[0][j]Ҳͬ��
�����(i, 0) �����������ϰ�֮���ϰ�֮�󣨰����ϰ��������߲�����λ���ˣ������ϰ�֮���dp[i][0]Ӧ�û��ǳ�ʼֵ0��
vector<vector<int>> dp(m, vector<int>(n, 0));
for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
4.ȷ������˳��
����Ҫ��һ�µ��ƹ�ʽdp[i][j] = dp[i - 1][j] + dp[i][j - 1]��dp[i][j]���Ǵ����Ϸ������Ƶ���������ô������һ��һ������Ϳ����ˡ�
�����Ϳ��Ա�֤�Ƶ�dp[i][j]��ʱ��dp[i - 1][j] �� dp[i][j - 1]һ��������ֵ�ġ�
for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 1) continue;
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
}
5.�����Ƶ�dp����
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //����������յ�������ϰ���ֱ�ӷ���0
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;//�����ϰ�����
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = { {0, 0, 0},{0, 1, 0 },{0, 0, 0 } };

    Solution so;
    int res = so.uniquePathsWithObstacles(obstacleGrid);
    cout << "dp[" << obstacleGrid.size() - 1 << "][" << obstacleGrid[0].size() - 1 << "]= " << res;
    return 0;
} 