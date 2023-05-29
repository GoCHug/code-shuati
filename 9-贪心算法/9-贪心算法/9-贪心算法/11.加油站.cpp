#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ֲ����ţ���ǰ�ۼ�rest[i]�ĺ�curSumһ��С��0����ʼλ������Ҫ��i+1����Ϊ��i֮ǰ��ʼһ�����С�
//ȫ�����ţ��ҵ�������һȦ����ʼλ�á�
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // ��ǰ�ۼ�rest[i]�� curSumһ��С��0
                start = i + 1;  // ��ʼλ�ø���Ϊi+1
                curSum = 0;     // curSum��0��ʼ
            }
        }
        if (totalSum < 0) return -1; // ˵����ô�߶���������һȦ��
        return start;
    }
};


int main() {
    vector<int> gas = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };

    Solution so;
    int res = so.canCompleteCircuit(gas, cost);

    cout << res;
    return 0;
}