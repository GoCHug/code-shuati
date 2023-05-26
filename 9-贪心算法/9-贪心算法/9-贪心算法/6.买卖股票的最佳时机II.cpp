#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ֲ����ţ��ռ�ÿ���������ȫ�����ţ�����������
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit += max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};

int main() {
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };

    Solution so;
    int res = so.maxProfit(prices);

    cout << res;
    return 0;
}