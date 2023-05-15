#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//我们需要一个队列，这个队列放进去窗口里的元素，随着窗口的移动，队列也一进一出，
//每次移动之后，队列告诉我们里面的最大值是什么。

class Solution {
public:
    //每次窗口移动的时候，调用pop(滑动窗口中移除元素的数值)，
    //push(滑动窗口添加元素的数值)，front()返回我们要的最大值。
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        // 先将前k的元素放进队列
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());//记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);// 滑动窗口移除最前面元素
            que.push(nums[i]);// 滑动窗口前加入最后面的元素
            res.push_back(que.front());
        }
        return res;
    }
};

int main() {
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;

    Solution so;
    vector<int> res = so.maxSlidingWindow(nums, k);
    for (int& x : res) {
        cout << x << " ";
    }
    return 0;
}