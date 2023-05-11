#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		int lenA = 0;
		int lenB = 0;
		ListNode* curA = headA;
		ListNode* curB = headB;

		while (curA) {
			curA = curA->next;
			lenA++;
		}
		while (curB) {
			curB = curB->next;
			lenB++;
		}
		if (lenA < lenB) return getIntersectionNode(headB, headA);//Ϊ���õ�һ�������ǳ����Ǹ�����
    
		int gap = lenA - lenB;
		curA = headA;
		curB = headB;
		while (gap--) {
			curA = curA->next;
		}
		while (curA) {
			if (curA == curB) return curA;
			curA = curA->next;
			curB = curB->next;
		}
		return NULL;
	}
};

int main() {
	//��������A
	vector<int> valuesA{ 4,1,8,4,5 };
	ListNode* headA = new ListNode(valuesA[0]);//����ͷ
	ListNode* curA = headA;

	ListNode* newNode = new ListNode(valuesA[1]);
	curA->next = newNode;
	newNode = new ListNode(valuesA[2]);
	curA->next->next = newNode;
	newNode = new ListNode(valuesA[3]);
	curA->next->next->next = newNode;
	newNode = new ListNode(valuesA[4]);
	curA->next->next->next->next = newNode;


	//��������B
	vector<int> valuesB{ 5,0,1,8,4,5 };
	ListNode* headB = new ListNode(valuesB[0]);//����ͷ
	ListNode* curB = headB;

	newNode = new ListNode(valuesB[1]);
	curB->next = newNode;
	newNode = new ListNode(valuesB[2]);
	curB->next->next = newNode;

	curB->next->next->next = curA->next->next;


	cout << "Before The Linked listA is: ";
	curA = headA;
	while (curA) {
		cout << curA->val;
		if (curA->next) {//�ж�ʱ�������һ���ڵ㣬��������һ���ڵ㣬next�ǿվͲ������ͷ
			cout << " -> ";
		}
		curA = curA->next;
	}
	cout << endl;

	cout << "Before The Linked listB is: ";
	curB = headB;
	while (curB) {
		cout << curB->val;
		if (curB->next) {//�ж�ʱ�������һ���ڵ㣬��������һ���ڵ㣬next�ǿվͲ������ͷ
			cout << " -> ";
		}
		curB = curB->next;
	}
	cout << endl;

	//���ú���
	Solution s;
	int n = 1;
	ListNode* ans = s.getIntersectionNode(headA, headB);

	cout << "After The Linked listA is: ";
	ListNode* cur = ans;
	while (cur) {
		cout << cur->val;
		if (cur->next) {//�ж�ʱ�������һ���ڵ㣬��������һ���ڵ㣬next�ǿվͲ������ͷ
			cout << " -> ";
		}
		cur = cur->next;
	}
	cout << endl;

	return 0;
}