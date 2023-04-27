#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//链表定义
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}//节点构造函数
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0, head);
		ListNode* cur = dummyHead;
		
		while (cur->next) {//！！！！循环需要判断cur->next是否为空，不要写习惯了就判断cur是否为空
			if (cur->next->val == val) {
				ListNode* tmp = cur->next;//释放内存
				cur->next = cur->next->next;
				delete tmp;
			}
			else {//！！！！一定要写在else里，不要不写else
				cur = cur->next;
			}	
		}
		return dummyHead->next;
	}
};

int main() {
	//创建链表
	vector<int> values{ 1,2,6,3,4,5,6 };
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

	//调用移除链表元素的函数
	Solution s;
	int val = 6;
	ListNode* ans = s.removeElements(head, val);

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