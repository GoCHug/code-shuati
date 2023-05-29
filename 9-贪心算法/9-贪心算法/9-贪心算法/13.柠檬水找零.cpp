#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
ֻ��Ҫά�����ֽ���������5��10��20�����������������
���һ���˵���5��ֱ�����¡�
��������˵���10������һ��5������һ��10
��������˵���20����������һ��10��һ��5���������������������5

�ֲ����ţ������˵�20������������Ԫ10����ɱ������㡣
ȫ�����ţ����ȫ���˵������㡣
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            // ���һ
            if (bill == 5) five++;
            // �����
            if (bill == 10) {
                if (five <= 0) return false;
                ten++;
                five--;
            }
            // �����
            if (bill == 20) {
                // ��������10��Ԫ����Ϊ5��Ԫ�������ô������ܶ����žͶ�����
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                    twenty++; // ��ʵ���д������ɾ�ˣ���Ϊ��¼20�Ѿ�û�������ˣ�������20������
                }
                else if (five >= 3) {
                    five -= 3;
                    twenty++; // ͬ�����д���Ҳ����ɾ��
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