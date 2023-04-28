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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;//����cur����һ���ڵ�
            cur->next = pre;//��ת����
            pre = cur;
            cur = tmp;
        }
        return pre;//pre���ָ�����һ���ڵ㣬���Ƿ�ת���ͷ�ڵ�
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
	ListNode* ans = s.reverseList(head);

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