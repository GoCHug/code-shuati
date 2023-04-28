#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next && cur->next->next) {//�������ڵ����ʱ����ѭ��
            ListNode* tmp1 = cur->next;//�����һ���ڵ�
            cur->next = cur->next->next;
            ListNode* tmp2 = cur->next->next;//����ڶ����ڵ�next�Ľڵ�
            cur->next->next = tmp1;
            tmp1->next = tmp2;

			cur = cur->next->next;//cur�ƶ������ڵ㣬׼����һ��
        }
        return dummyHead->next;
    }
};

int main() {
	//��������
	vector<int> values{ 1,2,3,4,5 };
	ListNode* head = new ListNode(values[0]);//����ͷ
	ListNode* cur = head;
	for (int i = 1; i < values.size(); ++i) {
		ListNode* newNode = new ListNode(values[i]);
		cur->next = newNode;
		cur = newNode;
	}

	cout << "Before The Linked list is: ";
	cur = head;
	while (cur) {
		cout << cur->val;
		if (cur->next) {//�ж�ʱ�������һ���ڵ㣬��������һ���ڵ㣬next�ǿվͲ������ͷ
			cout << " -> ";
		}
		cur = cur->next;
	}

	cout << endl;

	//���ú���
	Solution s;
	ListNode* ans = s.swapPairs(head);

	cout << "After The Linked list is: ";
	cur = ans;
	while (cur) {
		cout << cur->val;
		if (cur->next) {//�ж�ʱ�������һ���ڵ㣬��������һ���ڵ㣬next�ǿվͲ������ͷ
			cout << " -> ";
		}
		cur = cur->next;
	}
	return 0;
}