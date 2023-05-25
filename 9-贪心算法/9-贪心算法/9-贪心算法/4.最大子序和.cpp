#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) result = count;// ȡ�����ۼƵ����ֵ���൱�ڲ���ȷ�����������ֹλ�ã�
            if (count < 0) count = 0;// �൱���������������ʼλ�ã���Ϊ��������һ���������ܺ�
        }
        return result;
    }
};

int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    Solution so;
    int res = so.maxSubArray(nums);

    cout << res;
    return 0;
}