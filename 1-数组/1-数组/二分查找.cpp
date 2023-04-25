#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    ////����ұ�
    //int search(vector<int>& nums, int target) {
    //    int left = 0;
    //    int right = nums.size() - 1; // ����target������ұյ������[left, right]
    //    while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч�������� <=
    //        int middle = left + ((right - left) / 2);// ��ֹ��� ��ͬ��(left + right)/2
    //        if (target < nums[middle]) {
    //            right = middle - 1; // target �������䣬����[left, middle - 1]
    //        }
    //        else if (nums[middle] < target) {
    //            left = middle + 1; // target �������䣬����[middle + 1, right]
    //        }
    //        else { // nums[middle] == target
    //            return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
    //        }
    //    }
    //    // δ�ҵ�Ŀ��ֵ
    //    return -1;

    //����ҿ�
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) { //left = right������������������� ����[1,1)û�����壬�Ͳ���Ҫ����ѭ������
            int middle = left + (right - left) / 2;
            if (target < nums[middle]) {
                right = middle;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int target = 9;

    int res = s.search(nums, target);
    cout << res << endl;
    return 0;
}