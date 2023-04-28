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
    //双指针的经典应用，如果要删除倒数第n个节点
    //让fast移动n步，然后让fast和slow同时移动，直到fast指向链表末尾。删掉slow所指向的节点就可以了。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while (n-- && fast) {
            fast = fast->next;
        }
        if (fast) fast = fast->next;//fast首先走n + 1步，这样同时移动的时候slow才能指向删除节点的上一个节点（方便做删除操作）
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
		if (tmp) {//tmp肯定是不空的，但是不写这个if判断一下，编译器会报警告
			slow->next = tmp->next;
			delete tmp;
		}

        return dummyHead->next;
    }
};

int main() {
	//创建链表
	vector<int> values{ 1,2,3,4,5 };
	ListNode* head = new ListNode(values[0]);//链表头
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
		if (cur->next) {//判断时候是最后一个节点，如果是最后一个节点，next是空就不输出箭头
			cout << " -> ";
		}
		cur = cur->next;
	}

	cout << endl;

	//调用函数
	Solution s;
	int n = 1;
	ListNode* ans = s.removeNthFromEnd(head, n);

	cout << "After The Linked list is: ";
	cur = ans;
	while (cur) {
		cout << cur->val;
		if (cur->next) {//判断时候是最后一个节点，如果是最后一个节点，next是空就不输出箭头
			cout << " -> ";
		}
		cur = cur->next;
	}
	return 0;
}
