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
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {//˵���л�
                ListNode* index1 = fast;//������
                ListNode* index2 = head;//���
                while (index1 != index2) {//�жϲ���� ��������ȣ������һ���ڵ�����
                    index1 = index1->next;
                    index2 = index2->next;
                }
				return index1;
            }
        }
		return NULL;
    }
};

int main() {
	//��������
	vector<int> values{ 3,2,0,-4 };
	ListNode* head = new ListNode(values[0]);//����ͷ
	ListNode* cur = head;
	ListNode* tmp = NULL;//�������滷�νڵ�
	int pos = 2;
	for (int i = 1; i < values.size(); ++i) {
		ListNode* newNode = new ListNode(values[i]);
		if (i == pos) tmp = newNode;
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = tmp;

	cout << "Before The Linked list is: ";
	cur = head;
	for (int i = 0; i < 5; i++) {
		if (cur) {
			cout << cur->val << " ";
			cur = cur->next;
		}
	}

	cout << endl;

	//���ú���
	Solution s;
	int n = 1;
	ListNode* ans = s.detectCycle(head);

	cout << ans->val;

	return 0;
}