#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = { 0 }; // iΪ�ַ���hash[i]Ϊ�ַ����ֵ����λ��
        for (int i = 0; i < S.size(); i++) { // ͳ��ÿһ���ַ������ֵ�λ��
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']); // �ҵ��ַ����ֵ���Զ�߽�
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> intervals = { {1,2} ,{2,3},{3,4},{1,3} };

    Solution so;
    int res = so.eraseOverlapIntervals(intervals);

    cout << res;
    return 0;
}