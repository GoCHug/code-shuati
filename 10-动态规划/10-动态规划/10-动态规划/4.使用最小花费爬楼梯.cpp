#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]�Ķ���Ϊ�������į�������ѵ���������Ϊdp[i]��
2.״̬ת�Ʒ��̣�
����������;���õ�dp[i]��һ����dp[i-1] һ����dp[i-2]��
dp[i - 1] ���� dp[i] ��Ҫ���� dp[i - 1] + cost[i - 1]��
dp[i - 2] ���� dp[i] ��Ҫ���� dp[i - 2] + cost[i - 2]��
��ô������ѡ��dp[i - 1]�����Ǵ�dp[i - 2]���أ�
һ����ѡ��С�ģ�����dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
3.dp�����ʼ����
��Ŀ��������ȷ˵�� �������ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ���
Ҳ����˵ ���� �� 0 ��̨���ǲ����ѵģ����� ��0 ��̨�� �������Ļ�����Ҫ���� cost[0]��
���Գ�ʼ�� dp[0] = 0��dp[1] = 0;
4.ȷ������˳��
��Ϊ��ģ��̨�ף�����dp[i]��dp[i-1]dp[i-2]�Ƴ��������Ǵ�ǰ�������cost����Ϳ�����
5.�����Ƶ�dp����
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[n];
    }
};

int main() {
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };

    Solution so;
    int res = so.minCostClimbingStairs(cost);
    cout << "dp[" << cost.size() << "] = " << res;
    return 0;
}