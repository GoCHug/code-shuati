#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/*
局部最优：当气球出现重叠，一起射，所用弓箭最少。
全局最优：把所有气球射爆所用弓箭最少。
*/
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);

        int result = 1; // points 不为空至少需要一支箭
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {  // 气球i和气球i-1不挨着，注意这里不是>=
                result++; // 需要一支箭
            }
            else {  // 气球i和气球i-1挨着
                points[i][1] = min(points[i - 1][1], points[i][1]); // 更新重叠气球最小右边界
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> people = { {10,16} ,{2,8},{1,6},{7,12}};

    Solution so;
    int res = so.findMinArrowShots(people);

    cout << res;
    return 0;
}