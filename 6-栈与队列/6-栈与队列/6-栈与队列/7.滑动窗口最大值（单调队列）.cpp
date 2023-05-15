#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//������Ҫһ�����У�������зŽ�ȥ�������Ԫ�أ����Ŵ��ڵ��ƶ�������Ҳһ��һ����
//ÿ���ƶ�֮�󣬶��и���������������ֵ��ʲô��

class Solution {
public:
    //ÿ�δ����ƶ���ʱ�򣬵���pop(�����������Ƴ�Ԫ�ص���ֵ)��
    //push(�����������Ԫ�ص���ֵ)��front()��������Ҫ�����ֵ��
    class MyQueue { //�������У��Ӵ�С��
    public:
        deque<int> que; // ʹ��deque��ʵ�ֵ�������
        // ÿ�ε�����ʱ�򣬱Ƚϵ�ǰҪ��������ֵ�Ƿ���ڶ��г���Ԫ�ص���ֵ���������򵯳���
        // ͬʱpop֮ǰ�ж϶��е�ǰ�Ƿ�Ϊ�ա�
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // ���push����ֵ�������Ԫ�ص���ֵ����ô�ͽ����к�˵���ֵ������ֱ��push����ֵС�ڵ��ڶ������Ԫ�ص���ֵΪֹ��
        // �����ͱ����˶��������ֵ�ǵ����Ӵ�С���ˡ�
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // ��ѯ��ǰ����������ֵ ֱ�ӷ��ض���ǰ��Ҳ����front�Ϳ����ˡ�
        int front() {
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        // �Ƚ�ǰk��Ԫ�طŽ�����
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());//��¼ǰk��Ԫ�ص����ֵ
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);// ���������Ƴ���ǰ��Ԫ��
            que.push(nums[i]);// ��������ǰ����������Ԫ��
            res.push_back(que.front());
        }
        return res;
    }
};

int main() {
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;

    Solution so;
    vector<int> res = so.maxSlidingWindow(nums, k);
    for (int& x : res) {
        cout << x << " ";
    }
    return 0;
}