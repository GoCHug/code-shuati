#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int sum = getSum(n);
            if (1 == sum) return true;
            if (set.find(sum) != set.end()) {//˵�����sum�������ֹ�������ѭ����
                return false;
            }
            else {
                set.insert(sum);
            }
            n = sum;//����n
        }
    }
};

int main() {
    int n = 19;

    Solution so;
    bool res = so.isHappy(n);
    cout << res;

    return 0;
}