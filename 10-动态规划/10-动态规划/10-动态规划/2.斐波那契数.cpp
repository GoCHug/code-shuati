#include <iostream>

using namespace std;

/*
1.dp[i]�Ķ���Ϊ���±��i������쳲�������ֵ��dp[i]
2.״̬ת�Ʒ��� dp[i] = dp[i - 1] + dp[i - 2];
3.dp�����ʼ�� dp[0] = 0;dp[1] = 1;
4.ȷ������˳��
5.�����Ƶ�dp����
*/

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            cout  << "dp[" << i - 2 << "] = " << dp[0] << " dp[" << i - 1 << "] = " << dp[1] << " dp["<< i << "] = " << sum << endl;
            dp[0] = dp[1];
            dp[1] = sum;

        }
        return dp[1];

    }
};

int main() {
    int n = 8;

    Solution so;
    int res = so.fib(n);
    cout << "dp[" << n << "] = " << res;
    return 0;
}