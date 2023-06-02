#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]�Ķ���Ϊ��dp[i][j] ����ʾ�ӣ�0 ��0����������(i, j) ��dp[i][j]����ͬ��·����
2.״̬ת�Ʒ��̣�
��Ҫ��dp[i][j]��ֻ���������������Ƶ���������dp[i - 1][j] �� dp[i][j - 1]��
��ʱ�ڻع�һ�� dp[i - 1][j] ��ʾɶ���Ǵ�(0, 0)��λ�õ�(i - 1, j)�м���·����dp[i][j - 1]ͬ��
��ô����Ȼ��dp[i][j] = dp[i - 1][j] + dp[i][j - 1]����Ϊdp[i][j]ֻ���������������
3.dp�����ʼ����
��γ�ʼ���أ�����dp[i][0]һ������1����Ϊ��(0, 0)��λ�õ�(i, 0)��·��ֻ��һ������ôdp[0][j]Ҳͬ��
for (int i = 0; i < m; i++) dp[i][0] = 1;
for (int j = 0; j < n; j++) dp[0][j] = 1;
4.ȷ������˳��
����Ҫ��һ�µ��ƹ�ʽdp[i][j] = dp[i - 1][j] + dp[i][j - 1]��dp[i][j]���Ǵ����Ϸ������Ƶ���������ô������һ��һ������Ϳ����ˡ�
�����Ϳ��Ա�֤�Ƶ�dp[i][j]��ʱ��dp[i - 1][j] �� dp[i][j - 1]һ��������ֵ�ġ�
5.�����Ƶ�dp����
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    int m = 3, n = 7;

    Solution so;
    int res = so.uniquePaths(m, n);
    cout << "dp[" << m - 1 << "][" << n - 1 << "]= " << res;
    return 0;
}