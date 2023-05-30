#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; // ��Ϊ��߽�����
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0; // ע�������0��ʼ����Ϊ�Ǽ�¼�ص�����
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) { //�ص����
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);//�൱��ɾ���ص����俿�ҵ�����
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> intervals = { {1,2} ,{2,3},{3,4},{1,3} };

    Solution so;
    int res = so.eraseOverlapIntervals(intervals);

    cout << res;
    return 0;
}