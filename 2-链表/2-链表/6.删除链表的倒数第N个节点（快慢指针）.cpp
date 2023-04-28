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
    //˫ָ��ľ���Ӧ�ã����Ҫɾ��������n���ڵ�
    //��fast�ƶ�n����Ȼ����fast��slowͬʱ�ƶ���ֱ��fastָ������ĩβ��ɾ��slow��ָ��Ľڵ�Ϳ����ˡ�
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while (n-- && fast) {
            fast = fast->next;
        }
        if (fast) fast = fast->next;//fast������n + 1��������ͬʱ�ƶ���ʱ��slow����ָ��ɾ���ڵ����һ���ڵ㣨������ɾ��������
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
		if (tmp) {//tmp�϶��ǲ��յģ����ǲ�д���if�ж�һ�£��������ᱨ����
			slow->next = tmp->next;
			delete tmp;
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
	int n = 1;
	ListNode* ans = s.removeNthFromEnd(head, n);

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
