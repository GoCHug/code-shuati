#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ֲ����ţ���ǰ���ƶ����뾡���ܶ��ߣ������û���յ㣬�����ټ�һ���������ţ�һ�������ܶ��ߣ��Ӷ��ﵽ��С������
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        
        int cur = 0;// ��ǰ������Զ�����±�
        int next = 0;// ��һ��������Զ�����±�
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            next =max(next, i + nums[i]);// ������һ��������Զ�����±�
            if (i == cur) {// ������ǰ������Զ�����±�
                res++;
                cur = next; // ���µ�ǰ������Զ�����±꣨�൱�ڼ����ˣ�
                if (cur >= nums.size() - 1) break;// ��ǰ������Զ�ൽ�Ｏ���յ㣬������ans++�����ˣ�ֱ�ӽ���

            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = { 2,3,1,1,4 };

    Solution so;
    int res = so.jump(nums);

    cout << res;
    return 0;
}