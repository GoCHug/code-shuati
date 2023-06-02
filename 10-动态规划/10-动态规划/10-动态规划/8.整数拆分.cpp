#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]�Ķ���Ϊ��dp[i]���������i�����Եõ������˻�Ϊdp[i]��
2.״̬ת�Ʒ��̣�
j��1������i��j * (i - j) �ǵ����İ��������Ϊ��������ˣ�
��j * dp[i - j]�ǲ�ֳ������Լ��������ϵĸ�����ˡ�
dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j});
��ô��ȡ���ֵ��ʱ��Ϊʲô��Ҫ�Ƚ�dp[i]�أ�
��Ϊ�ڵ��ƹ�ʽ�Ƶ��Ĺ����У�ÿ�μ���dp[i]��ȡ���Ķ��ѡ�
3.dp�����ʼ����
��dp[i]�Ķ�����˵��dp[0] dp[1] �Ͳ�Ӧ�ó�ʼ����Ҳ����û���������ֵ��
������ֻ��ʼ��dp[2] = 1����dp[i]�Ķ�����˵���������2���õ������˻���1�����û���κ����飡
4.ȷ������˳��
dp[i] ������ dp[i - j]��״̬�����Ա���iһ���Ǵ�ǰ������������dp[i - j]����dp[i]��
5.�����Ƶ�dp����
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));//�Ƚ�dp[i]����Ϊ�̶���i��j�ڱ䣬���²�ͬj�µ�dp[i]
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 7;

    Solution so;
    int res = so.integerBreak(n);
    cout << "dp[" <<  n << "]= " << res;
    return 0;
}