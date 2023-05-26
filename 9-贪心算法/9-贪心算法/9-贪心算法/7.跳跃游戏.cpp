#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//̰���㷨�ֲ����Ž⣺ÿ��ȡ�����Ծ������ȡ��󸲸Ƿ�Χ����
//�������Ž⣺���õ�������󸲸Ƿ�Χ�����Ƿ��ܵ��յ㡣
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // ֻ��һ��Ԫ�أ������ܴﵽ
        //i ÿ���ƶ�ֻ���� cover �ķ�Χ���ƶ���ÿ�ƶ�һ��Ԫ�أ�cover �õ���Ԫ����ֵ���µĸ��Ƿ�Χ���Ĳ��䣬�� i �����ƶ���ȥ��
        for (int i = 0; i <= cover; i++) { // ע��������С�ڵ���cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // ˵�����Ը��ǵ��յ���
        }
        return false;
    }
};

int main() {
    vector<int> nums = { 2,3,1,1,4 };

    Solution so;
    int res = so.canJump(nums);

    cout << res;
    return 0;
}