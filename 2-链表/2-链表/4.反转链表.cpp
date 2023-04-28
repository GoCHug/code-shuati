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
            ListNode* tmp = cur->next;//保存cur的下一个节点
            cur->next = pre;//反转操作
            pre = cur;
            cur = tmp;
        }
        return pre;//pre最后指向最后一个节点，就是反转后的头节点
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
	ListNode* ans = s.reverseList(head);

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