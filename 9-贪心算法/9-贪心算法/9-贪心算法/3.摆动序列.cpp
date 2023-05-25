#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // ��ǰһ�Բ�ֵ
        int preDiff = 0; // ǰһ�Բ�ֵ
        int result = 1;  // ��¼��ֵ����������Ĭ���������ұ���һ����ֵ
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // ���ַ�ֵ
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff; // ע�����ֻ�ڰڶ��仯��ʱ�����prediff
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = { 1, 7, 4, 9, 2, 5 };

    Solution so;
    int res = so.wiggleMaxLength(nums);

    cout << res;
    return 0;
}