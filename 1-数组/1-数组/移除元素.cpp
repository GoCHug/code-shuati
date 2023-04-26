#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    ////�����ⷨ
    //int removeElement(vector<int>& nums, int val) {
    //    int size = nums.size();
    //    for (int i = 0; i < size; i++) {
    //        if (nums[i] == val) { // ������Ҫ�Ƴ���Ԫ�أ��ͽ����鼯����ǰ�ƶ�һλ
    //            for (int j = i + 1; j < size; j++) {
    //                nums[j - 1] = nums[j];
    //            }
    //            i--; // ��Ϊ�±�i�Ժ����ֵ����ǰ�ƶ���һλ������iҲ��ǰ�ƶ�һλ
    //            size--; // ��ʱ����Ĵ�С-1
    //        }
    //    }
    //    return size;
    //}

    ////����ָ�뷨 û�иı�Ԫ�ص����λ�ã�ֻ��Ҫ������������������
    //int removeElement(vector<int>& nums, int val) {
    //    int slowIndex = 0;//��ָ�룺ָ����� �������±��λ��
    //    //��ָ�룺Ѱ���������Ԫ�� ����������ǲ�����Ŀ��Ԫ�ص�����
    //    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
    //        if (val != nums[fastIndex]) {
    //            nums[slowIndex++] = nums[fastIndex];//��ָ��û�ҵ�val������ָ��һ���ƶ����ҵ���ֻ�ƶ���ָ��
    //        }
    //    }
    //    return slowIndex;
    //}

    //���˫ָ�뷨 �ı���Ԫ�����λ�ã�ȷ���ƶ�����Ԫ�أ�ֻ��Ҫ��������������һ��
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;//����ұ�
        while (left <= right) {//���ں�ʱ������Ч
            //�ҵ���ߵ���val��Ԫ��
            while (left <= right && nums[left] != val) {
                ++left;
            }
            //�ҵ��б߲�����val��Ԫ��
            while (left <= right && nums[right] == val) {
                --right;
            }
            //���ұ߲�����val��ֵ������ߵ���val��ֵ
            if (left < right) {
                nums[left++] = nums[right--];
            }
        }
        return left;//leftָ����������ĩβ����һ��Ԫ��
    }

};

int main() {
    Solution s;
    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    int val = 2;
    int res = s.removeElement(nums, val);
    cout << res << endl;
    return 0;
}

