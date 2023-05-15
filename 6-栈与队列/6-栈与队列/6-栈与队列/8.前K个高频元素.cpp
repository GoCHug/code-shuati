#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
这道题目主要涉及到如下三块内容：
1.要统计元素出现频率
2.对频率排序
3.找出前K个高频元素
*/
//用小顶堆，因为要统计最大前k个元素，只有小顶堆每次将最小的元素弹出，
//最后小顶堆里积累的才是前k个最大元素

class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        //左大于右就会建立小顶堆
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1.要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 2.对频率排序
        // 定义一个小顶堆，大小为k
        //存储类型为 pair<int, int> 的元素，使用 vector<pair<int, int>> 作为底层容器，
        // 使用 mycomparison 类型的比较函数进行元素的比较操作。
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 3.找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main() {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    Solution so;
    vector<int> res = so.topKFrequent(nums, k);

    for (int& x : res) {
        cout << x << " ";
    }
    return 0;
}