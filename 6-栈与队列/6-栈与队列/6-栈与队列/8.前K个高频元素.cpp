#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
�����Ŀ��Ҫ�漰�������������ݣ�
1.Ҫͳ��Ԫ�س���Ƶ��
2.��Ƶ������
3.�ҳ�ǰK����ƵԪ��
*/
//��С���ѣ���ΪҪͳ�����ǰk��Ԫ�أ�ֻ��С����ÿ�ν���С��Ԫ�ص�����
//���С��������۵Ĳ���ǰk�����Ԫ��

class Solution {
public:
    // С����
    class mycomparison {
    public:
        //������ҾͻὨ��С����
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1.Ҫͳ��Ԫ�س���Ƶ��
        unordered_map<int, int> map; // map<nums[i],��Ӧ���ֵĴ���>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 2.��Ƶ������
        // ����һ��С���ѣ���СΪk
        //�洢����Ϊ pair<int, int> ��Ԫ�أ�ʹ�� vector<pair<int, int>> ��Ϊ�ײ�������
        // ʹ�� mycomparison ���͵ıȽϺ�������Ԫ�صıȽϲ�����
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // �ù̶���СΪk��С���ѣ�ɨ������Ƶ�ʵ���ֵ
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // ����ѵĴ�С������K������е�������֤�ѵĴ�СһֱΪk
                pri_que.pop();
            }
        }

        // 3.�ҳ�ǰK����ƵԪ�أ���ΪС�����ȵ���������С�ģ����Ե��������������
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main() {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    Solution so;
    vector<int> res = so.topKFrequent(nums, k);

    for (int& x : res) {
        cout << x << " ";
    }
    return 0;
}