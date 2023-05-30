#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = { 0 }; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
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