#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    ////暴力排序 O(n + nlogn) sort的时间复杂度是nlogn
    //vector<int> sortedSquares(vector<int>& A) {
    //    for (int i = 0; i < A.size(); i++) {
    //        A[i] *= A[i];
    //    }
    //    sort(A.begin(), A.end()); // 快速排序
    //    return A;
    //}

    //双指针法 O(n)
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;//res数组的下标 从最后一个开始
        int left = 0;
        int right = A.size() - 1;
        vector<int> res(A.size());
        while (left <= right) {
            if (A[left] * A[left] <= A[right] * A[right]) {
                res[k--] = A[right] * A[right];
                right--;
            }
            else {
                res[k--] = A[left] * A[left];
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = { -4,-1,0,3,10 };
    vector<int> res = s.sortedSquares(nums);

    for (auto n : res) {
        cout << n << " ";
    }

    return 0;
}