#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//贪心算法局部最优解：每次取最大跳跃步数（取最大覆盖范围），
//整体最优解：最后得到整体最大覆盖范围，看是否能到终点。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        //i 每次移动只能在 cover 的范围内移动，每移动一个元素，cover 得到该元素数值（新的覆盖范围）的补充，让 i 继续移动下去。
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
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