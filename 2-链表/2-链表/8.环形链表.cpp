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
主要考察两知识点
一、判断链表是否环：
快慢指针法
fast每次移动2个节点，slow每次移动1个节点，途中相遇说明有环
相对于slow来说，fast是一个节点一个节点的靠近slow的，所以fast一定可以和slow重合。
二、如果有环，如何找到这个环的入口：
假设从头结点到环形入口节点的节点数为x。环形入口节点到相遇节点节点数为y。相遇节点到环形入口节点节点数为 z。
那么相遇时：slow指针走过的节点数为: x + y，fast指针走过的节点数：x + y + n (y + z)，
n为fast指针在环内走了n圈才遇到slow指针， （y+z）为 一圈内节点的个数A。
fast指针走过的节点数 = slow指针走过的节点数 * 2
(x + y) * 2 = x + y + n (y + z) >> x + y = n (y + z) >> x = n (y + z) - y >> x = (n - 1) (y + z) + z
结论：从头结点出发一个指针，从相遇节点也出发一个指针，每次只走一个节点，当这两个指针相遇的时候就是环形入口的节点
*/

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {//因为fast是两步两步跳的，所以要判断fast和fast->next
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {//说明链表有环
                ListNode* index1 = fast;//环中相遇节点
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;//返回环入口
            }
        }
        return NULL;
    }
};

int main() {
	//创建链表
	vector<int> values{ 3,2,0,-4 };
	ListNode* head = new ListNode(values[0]);//链表头
	ListNode* cur = head;
	ListNode* tmp = NULL;//用来保存环形节点
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

	//调用函数
	Solution s;
	int n = 1;
	ListNode* ans = s.detectCycle(head);

	cout << ans->val;

	return 0;
}