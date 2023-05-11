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
        fast = fast->next;//fast��n+1��
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
        if (cur->next) {//�ж�ʱ�������һ���ڵ㣬��������һ���ڵ㣬next�ǿվͲ������ͷ
            cout << " -> ";
        }
        cur = cur->next;
    }

    cout << endl;

    //���ú���
    Solution s;
    int n = 2;
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