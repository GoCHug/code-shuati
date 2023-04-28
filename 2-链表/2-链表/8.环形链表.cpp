#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
��Ҫ������֪ʶ��
һ���ж������Ƿ񻷣�
����ָ�뷨
fastÿ���ƶ�2���ڵ㣬slowÿ���ƶ�1���ڵ㣬;������˵���л�
�����slow��˵��fast��һ���ڵ�һ���ڵ�Ŀ���slow�ģ�����fastһ�����Ժ�slow�غϡ�
��������л�������ҵ����������ڣ�
�����ͷ��㵽������ڽڵ�Ľڵ���Ϊx��������ڽڵ㵽�����ڵ�ڵ���Ϊy�������ڵ㵽������ڽڵ�ڵ���Ϊ z��
��ô����ʱ��slowָ���߹��Ľڵ���Ϊ: x + y��fastָ���߹��Ľڵ�����x + y + n (y + z)��
nΪfastָ���ڻ�������nȦ������slowָ�룬 ��y+z��Ϊ һȦ�ڽڵ�ĸ���A��
fastָ���߹��Ľڵ��� = slowָ���߹��Ľڵ��� * 2
(x + y) * 2 = x + y + n (y + z) >> x + y = n (y + z) >> x = n (y + z) - y >> x = (n - 1) (y + z) + z
���ۣ���ͷ������һ��ָ�룬�������ڵ�Ҳ����һ��ָ�룬ÿ��ֻ��һ���ڵ㣬��������ָ��������ʱ����ǻ�����ڵĽڵ�
*/

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {//��Ϊfast�������������ģ�����Ҫ�ж�fast��fast->next
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {//˵�������л�
                ListNode* index1 = fast;//���������ڵ�
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;//���ػ����
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
	int pos = 1;
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