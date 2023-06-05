#include <iostream>
#include <vector>
using namespace std;

/*
1.dp����Ϊ�����ڱ������⣬��һ��д���� 
��ʹ�ö�ά���飬��dp[i][j] ��ʾ���±�Ϊ[0-i]����Ʒ������ȡ���Ž�����Ϊj�ı�������ֵ�ܺ�����Ƕ��١�
2.״̬ת�Ʒ��̣�
�ٻع�һ��dp[i][j]�ĺ��壺���±�Ϊ[0-i]����Ʒ������ȡ���Ž�����Ϊj�ı�������ֵ�ܺ�����Ƕ��١�
��ô���������������Ƴ���dp[i][j]��
������Ʒi����dp[i - 1][j]�Ƴ�������������Ϊj�����治����Ʒi������ֵ����ʱdp[i][j]����dp[i - 1][j]��
(��ʵ���ǵ���Ʒi���������ڱ���j������ʱ����Ʒi�޷��Ž������У����Ա����ڵļ�ֵ��Ȼ��ǰ����ͬ��)
����Ʒi����dp[i - 1][j - weight[i]]�Ƴ���dp[i - 1][j - weight[i]] Ϊ��������Ϊj - weight[i]��ʱ�򲻷���Ʒi������ֵ��
��ôdp[i - 1][j - weight[i]] + value[i] ����Ʒi�ļ�ֵ�������Ǳ�������Ʒi�õ�������ֵ
���Եݹ鹫ʽ�� dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
3.dp�����ʼ����
���ȴ�dp[i][j]�Ķ�������������������jΪ0�Ļ�����dp[i][0]��������ѡȡ��Щ��Ʒ��������ֵ�ܺ�һ��Ϊ0��
״̬ת�Ʒ��� dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
���Կ���i ���� i-1 �Ƶ���������ôiΪ0��ʱ���һ��Ҫ��ʼ����
dp[0][j]������iΪ0����ű��0����Ʒ��ʱ�򣬸��������ı������ܴ�ŵ�����ֵ��
��ô�����Ե� j < weight[0]��ʱ��dp[0][j] Ӧ���� 0����Ϊ���������ȱ��0����Ʒ������С��
��j >= weight[0]ʱ��dp[0][j] Ӧ����value[0]����Ϊ�����������㹻�ű��0��Ʒ��
�����ʼ�����£�
// ��ʼ�� dp
vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
for (int j = weight[0]; j <= bagweight; j++) {
    dp[0][j] = value[0];
}
4.ȷ������˳��
�ȱ��� ��Ʒ�����ȱ������������أ�
��ʵ�����ԣ��� �����ȱ�����Ʒ������⡣
5.�����Ƶ�dp����
*/

void test_2_wei_bag_problem1() {
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bagweight = 4;

    // ��ά����
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // ��ʼ��
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    // weight����Ĵ�С ������Ʒ����
    for (int i = 1; i < weight.size(); i++) { // ������Ʒ
        for (int j = 0; j <= bagweight; j++) { // ������������
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
    test_2_wei_bag_problem1();
}
