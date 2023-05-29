#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//局部最优：只要右边评分比左边大，右边的孩子就多一个糖果
//全局最优：相邻的孩子中，评分高的右孩子获得比左边孩子更多的糖果
//采用了两次贪心的策略：
//一次是从左到右遍历，只比较右边孩子评分比左边大的情况。
//一次是从右到左遍历，只比较左边孩子评分比右边大的情况。
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        // 从前向后
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        // 从后向前
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // 统计结果
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};


int main() {
    vector<int> ratings = { 1,0,2 };

    Solution so;
    int res = so.candy(ratings);

    cout << res;
    return 0;
}