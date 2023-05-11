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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while (n-- && fast) {
            fast = fast->next;
        }
        fast = fast->next;//fast走n+1步
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
    vector<int> nums = { 1, 2, 3, 4, 5 };
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < nums.size(); i++) {
        ListNode* newNode = new ListNode(nums[i]);
        cur->next = newNode;
        cur = cur->next;
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
    int n = 2;
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