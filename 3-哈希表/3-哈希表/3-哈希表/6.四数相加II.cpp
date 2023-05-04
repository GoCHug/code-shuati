#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;//key a+b的数值，value a+b出现的次数
        for (int a : nums1) {
            for (int b : nums2) {
                map[a + b]++;
            }
        }
        int count = 0;//统计a+b+c+d=0出现的次数
        for (int c : nums3) {
            for (int d : nums4) {
                if (map.find(0 - (c + d)) != map.end()) {//找到0 - (c + d)
                    count += map[0 - (c + d)];//加上使得当前c、d下abcd相加得0的次数
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> num1 = { 1,2 };
    vector<int> num2 = { -2,-1 };
    vector<int> num3 = { -1,2 };
    vector<int> num4 = { 0,2 };

    Solution so;
    int res = so.fourSumCount(num1, num2, num3, num4);

    cout << res;

    return 0;
}