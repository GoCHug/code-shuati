#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ֲ����ţ��þ���ֵ��ĸ�����Ϊ��������ǰ��ֵ�ﵽ����������ţ���������ʹﵽ���
//����һ��̰�ģ��ֲ����ţ�ֻ����ֵ��С�����������з�ת����ǰ��ֵ�Ϳ��Դﵽ���
//����������������{5, 3, 1}����ת1 �õ�-1 �� ��ת5�õ���-5 ����ˣ���ȫ�����ţ����� ����� �ﵽ���
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int min_abs = INT_MAX;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            min_abs = min(abs(nums[i]), min_abs);//��¼����ֵ��С����
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
            sum += nums[i];
        }

        if (k %= 2) {//��ʱ�Ѿ�ȫ���������ˣ�k������0����Ҫ��ȥ��С������
            sum -= 2 * min_abs;
        }
        return sum;
    }
};


int main() {
    vector<int> nums = { 3,-1,0,2 };
    int k = 3;

    Solution so;
    int res = so.largestSumAfterKNegations(nums, k);

    cout << res;
    return 0;
}