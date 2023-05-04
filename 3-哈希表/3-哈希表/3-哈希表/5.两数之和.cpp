#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;//key 元素，value 下标
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {//如果找到了
                return { iter->second, i };//iter是在i之前被插入在map中的，所以写在前面
            }
            //如果没找到匹配对，就把访问过的元素和下标加入到map中
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