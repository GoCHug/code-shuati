#include <iostream>
#include <vector>
using namespace std;

/*
1.dp[i]�Ķ���Ϊ��������i��¥�ݣ���dp[i]�ַ���
2.״̬ת�Ʒ��̣�
��dp[i]�Ķ�����Կ�����dp[i] ���������������Ƴ�����
������dp[i - 1]����i-1��¥�ݣ���dp[i - 1]�ַ�������ô��һ����һ��̨�ײ�����dp[i]��ô��
���о���dp[i - 2]����i-2��¥�ݣ���dp[i - 2]�ַ�������ô��һ��������̨�ײ�����dp[i]��ô��
��ôdp[i]���� dp[i - 1]��dp[i - 2]֮�ͣ�
����dp[i] = dp[i - 1] + dp[i - 2] ��
3.dp�����ʼ����
������һ��¥����һ�ַ�������������¥�������ַ�����
������dp[0]��γ�ʼ����ֻ��ʼ��dp[1] = 1��dp[2] = 2��Ȼ���i = 3��ʼ���ƣ������ŷ���dp[i]�Ķ��塣
4.ȷ������˳��
�ӵ��ƹ�ʽdp[i] = dp[i - 1] + dp[i - 2];�п��Կ���������˳��һ���Ǵ�ǰ��������
5.�����Ƶ�dp����
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }

    ////�Ż��ռ�İ汾
    ////���Ҹ�����Ϊ��������д���汾һ�͹��˹����������ˣ�������Թ�Ҫ���һ���Ż��ռ�Ļ���������ȥ�Ż���
    //int climbStairs(int n) {
    //    if (n <= 2) return n;
    //    vector<int> dp(3);
    //    dp[1] = 1;
    //    dp[2] = 2;
    //    for (int i = 3; i <= n; i++) {
    //        int sum = dp[1] + dp[2];
    //        dp[1] = dp[2];
    //        dp[2] = sum;
    //    }
    //    return dp[2];
    //}

};

int main() {
    int n = 8;

    Solution so;
    int res = so.climbStairs(n);
    cout << "dp[" << n << "] = " << res;
    return 0;
}