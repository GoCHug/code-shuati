#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());//����һ��ʼ�����˾�ȥ�أ�����-1 -1 2��ͳ�Ʋ�����
        // �ҳ�a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // ����֮�������һ��Ԫ���Ѿ������㣬��ô���������϶������ܴճ���Ԫ�飬ֱ�ӷ��ؽ���Ϳ�����
            if (nums[i] > 0) {
                return result;
            }
            // ����ȥ��a����������©��-1,-1,2 ��������������жϵ��ǽ�����������ظ���Ԫ��
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // ��ȷȥ��a����
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                // ȥ�ظ��߼�����������0��0��0 �����������ֱ�ӵ��� right<=left �ˣ��Ӷ�©���� 0,0,0 ������Ԫ��
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // �ȴ���һ�����֮����ȥ�ء�ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮�󣬶�b��cȥ�ء�����0 -1 -1 -1 1 1 1�ҵ���һ��0 -1 1������ָ�뿪ʼȥ���ƶ�
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;

                    // �ҵ���ʱ��˫ָ��ͬʱ����
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};

int main() {
    vector<int> num = { -1,0,1,2,-1,-4 };

    Solution so;
    vector<vector<int>> res = so.threeSum(num);
    for (auto& v : res) {
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}