#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    ////左闭右闭
    //int search(vector<int>& nums, int target) {
    //    int left = 0;
    //    int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
    //    while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
    //        int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
    //        if (target < nums[middle]) {
    //            right = middle - 1; // target 在左区间，所以[left, middle - 1]
    //        }
    //        else if (nums[middle] < target) {
    //            left = middle + 1; // target 在右区间，所以[middle + 1, right]
    //        }
    //        else { // nums[middle] == target
    //            return middle; // 数组中找到目标值，直接返回下标
    //        }
    //    }
    //    // 未找到目标值
    //    return -1;

    //左闭右开
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) { //left = right情况下在区间里无意义 比如[1,1)没有意义，就不需要进入循环找了
            int middle = left + (right - left) / 2;
            if (target < nums[middle]) {
                right = middle;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int target = 9;

    int res = s.search(nums, target);
    cout << res << endl;
    return 0;
}