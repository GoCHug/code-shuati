#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;//key Ԫ�أ�value �±�
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {//����ҵ���
                return { iter->second, i };//iter����i֮ǰ��������map�еģ�����д��ǰ��
            }
            //���û�ҵ�ƥ��ԣ��Ͱѷ��ʹ���Ԫ�غ��±���뵽map��
            //map.insert(pair<int, int>(nums[i], i));
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> num = { 2,7,11,15 };
    int target = 9;
    Solution so;
    vector<int> res = so.twoSum(num, target);
    for (auto& x : res) {
        cout << x << " ";
    }
    return 0;
}