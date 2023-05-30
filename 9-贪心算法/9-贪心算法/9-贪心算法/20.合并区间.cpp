#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result; // ���伯��Ϊ��ֱ�ӷ���
        // ����Ĳ���ʹ����lambda���ʽ
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });

        // ��һ������Ϳ��ԷŽ���������������ص�����result��ֱ�Ӻϲ�
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) { // �����ص�����
                // �ϲ����䣬ֻ�����ұ߽�ͺã���Ϊresult.back()����߽�һ������Сֵ����Ϊ���ǰ�����߽������
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]); // ���䲻�ص� 
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3} ,{2,6},{8,10},{15,18}};

    Solution so;
    vector<vector<int>> res = so.merge(intervals);

    for (vector<int>& vec : res) {
        for (int& t : vec) {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}