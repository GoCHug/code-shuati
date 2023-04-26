#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    ////暴力解法
    //int removeElement(vector<int>& nums, int val) {
    //    int size = nums.size();
    //    for (int i = 0; i < size; i++) {
    //        if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
    //            for (int j = i + 1; j < size; j++) {
    //                nums[j - 1] = nums[j];
    //            }
    //            i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
    //            size--; // 此时数组的大小-1
    //        }
    //    }
    //    return size;
    //}

    ////快慢指针法 没有改变元素的相对位置，只需要遍历该序列至多两次
    //int removeElement(vector<int>& nums, int val) {
    //    int slowIndex = 0;//慢指针：指向更新 新数组下标的位置
    //    //快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
    //    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
    //        if (val != nums[fastIndex]) {
    //            nums[slowIndex++] = nums[fastIndex];//快指针没找到val，两个指针一起移动，找到了只移动快指针
    //        }
    //    }
    //    return slowIndex;
    //}

    //相对双指针法 改变了元素相对位置，确保移动最少元素，只需要遍历该序列至多一次
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;//左闭右闭
        while (left <= right) {//等于号时区间有效
            //找到左边等于val的元素
            while (left <= right && nums[left] != val) {
                ++left;
            }
            //找到有边不等于val的元素
            while (left <= right && nums[right] == val) {
                --right;
            }
            //将右边不等于val的值覆盖左边等于val的值
            if (left < right) {
                nums[left++] = nums[right--];
            }
        }
        return left;//left指向最终数组末尾的下一个元素
    }

};

int main() {
    Solution s;
    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    int val = 2;
    int res = s.removeElement(nums, val);
    cout << res << endl;
    return 0;
}

