#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
只需要维护三种金额的数量，5，10和20。有如下三种情况：
情况一：账单是5，直接收下。
情况二：账单是10，消耗一个5，增加一个10
情况三：账单是20，优先消耗一个10和一个5，如果不够，再消耗三个5

局部最优：遇到账单20，优先消耗美元10，完成本次找零。
全局最优：完成全部账单的找零。
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            // 情况一
            if (bill == 5) five++;
            // 情况二
            if (bill == 10) {
                if (five <= 0) return false;
                ten++;
                five--;
            }
            // 情况三
            if (bill == 20) {
                // 优先消耗10美元，因为5美元的找零用处更大，能多留着就多留着
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                    twenty++; // 其实这行代码可以删了，因为记录20已经没有意义了，不会用20来找零
                }
                else if (five >= 3) {
                    five -= 3;
                    twenty++; // 同理，这行代码也可以删了
                }
                else return false;
            }
        }
        return true;
    }
};


int main() {
    vector<int> bills = { 5,5,5,10,20 };

    Solution so;
    bool res = so.lemonadeChange(bills);

    cout << res;
    return 0;
}