#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res_set;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int& n : nums2) {
            if (nums1_set.find(n) != nums1_set.end()) {//如果n在nums1中出现过
                res_set.insert(n);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};

int main() {
    vector<int> nums1 = { 1,2,2,1,3 };
    vector<int> nums2 = { 2,2,3 };

    Solution s;
    vector<int> res = s.intersection(nums1, nums2);
    for (int& x : res) {
        cout << x << " ";
    }

    return 0;
 }
