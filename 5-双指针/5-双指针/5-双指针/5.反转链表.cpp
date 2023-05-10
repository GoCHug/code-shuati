#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;

        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;//先更新pre
            cur = tmp;//再更新cur
        }
        return pre;
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