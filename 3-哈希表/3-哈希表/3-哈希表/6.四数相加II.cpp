#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;//key a+b����ֵ��value a+b���ֵĴ���
        for (int a : nums1) {
            for (int b : nums2) {
                map[a + b]++;
            }
        }
        int count = 0;//ͳ��a+b+c+d=0���ֵĴ���
        for (int c : nums3) {
            for (int d : nums4) {
                if (map.find(0 - (c + d)) != map.end()) {//�ҵ�0 - (c + d)
                    count += map[0 - (c + d)];//����ʹ�õ�ǰc��d��abcd��ӵ�0�Ĵ���
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