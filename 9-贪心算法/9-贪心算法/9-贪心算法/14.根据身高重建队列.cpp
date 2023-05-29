#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/*
所以在按照身高从大到小排序后：
局部最优：优先按身高高的people的k来插入。插入操作过后的people满足队列属性
全局最优：最后都做完插入操作，整个队列满足题目队列属性
*/
// 使用C++中的list（底层链表实现）比vector（数组）效率高得多。
class Solution {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que; // list底层是链表实现，插入效率比vector高的多
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1]; // 插入到下标为position的位置
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};


int main() {
    vector<vector<int>> people = { {7,0} ,{ 4,4},{7,1},{5,0},{ 6,1},{5,2} };

    Solution so;
    vector<vector<int>> res = so.reconstructQueue(people);

    for (vector<int>& vec : res) {
        for (int& t : vec) {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}