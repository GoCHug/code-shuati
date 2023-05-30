#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/*
�ֲ����ţ�����������ص���һ���䣬���ù������١�
ȫ�����ţ������������䱬���ù������١�
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

        int result = 1; // points ��Ϊ��������Ҫһ֧��
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {  // ����i������i-1�����ţ�ע�����ﲻ��>=
                result++; // ��Ҫһ֧��
            }
            else {  // ����i������i-1����
                points[i][1] = min(points[i - 1][1], points[i][1]); // �����ص�������С�ұ߽�
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