#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    ////�������� O(n + nlogn) sort��ʱ�临�Ӷ���nlogn
    //vector<int> sortedSquares(vector<int>& A) {
    //    for (int i = 0; i < A.size(); i++) {
    //        A[i] *= A[i];
    //    }
    //    sort(A.begin(), A.end()); // ��������
    //    return A;
    //}

    //˫ָ�뷨 O(n)
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;//res������±� �����һ����ʼ
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