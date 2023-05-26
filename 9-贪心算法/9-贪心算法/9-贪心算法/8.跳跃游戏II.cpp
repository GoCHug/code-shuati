#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//局部最优：当前可移动距离尽可能多走，如果还没到终点，步数再加一。整体最优：一步尽可能多走，从而达到最小步数。
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        
        int cur = 0;// 当前覆盖最远距离下标
        int next = 0;// 下一步覆盖最远距离下标
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            next =max(next, i + nums[i]);// 更新下一步覆盖最远距离下标
            if (i == cur) {// 遇到当前覆盖最远距离下标
                res++;
                cur = next; // 更新当前覆盖最远距离下标（相当于加油了）
                if (cur >= nums.size() - 1) break;// 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束

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