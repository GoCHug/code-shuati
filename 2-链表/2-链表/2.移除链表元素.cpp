#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//������
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}//�ڵ㹹�캯��
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0, head);
		ListNode* cur = dummyHead;
		
		while (cur->next) {//��������ѭ����Ҫ�ж�cur->next�Ƿ�Ϊ�գ���Ҫдϰ���˾��ж�cur�Ƿ�Ϊ��
			if (cur->next->val == val) {
				ListNode* tmp = cur->next;//�ͷ��ڴ�
				cur->next = cur->next->next;
				delete tmp;
			}
			else {//��������һ��Ҫд��else���Ҫ��дelse
				cur = cur->next;
			}	
		}
		return dummyHead->next;
	}
};

int main() {
	//��������
	vector<int> values{ 1,2,6,3,4,5,6 };
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

	//�����Ƴ�����Ԫ�صĺ���
	Solution s;
	int val = 6;
	ListNode* ans = s.removeElements(head, val);

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