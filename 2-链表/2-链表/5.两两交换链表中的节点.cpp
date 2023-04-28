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
        while (cur->next && cur->next->next) {//下两个节点存在时继续循环
            ListNode* tmp1 = cur->next;//保存第一个节点
            cur->next = cur->next->next;
            ListNode* tmp2 = cur->next->next;//保存第二个节点next的节点
            cur->next->next = tmp1;
            tmp1->next = tmp2;

			cur = cur->next->next;//cur移动两个节点，准备下一轮
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
	ListNode* ans = s.swapPairs(head);

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