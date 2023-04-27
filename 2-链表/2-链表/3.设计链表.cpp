#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/*
�������еĽڵ�Ӧ�þ߱��������ԣ�val �� next��

���������е����нڵ��±�� 0 ��ʼ��

ʵ�� MyLinkedList �ࣺ

MyLinkedList() ��ʼ�� MyLinkedList ����
int get(int index) ��ȡ�������±�Ϊ index �Ľڵ��ֵ������±���Ч���򷵻� - 1 ��
void addAtHead(int val) ��һ��ֵΪ val �Ľڵ���뵽�����е�һ��Ԫ��֮ǰ���ڲ�����ɺ��½ڵ���Ϊ����ĵ�һ���ڵ㡣
void addAtTail(int val) ��һ��ֵΪ val �Ľڵ�׷�ӵ���������Ϊ��������һ��Ԫ�ء�
void addAtIndex(int index, int val) ��һ��ֵΪ val �Ľڵ���뵽�������±�Ϊ index �Ľڵ�֮ǰ����� index ��������ĳ��ȣ���ô�ýڵ�ᱻ׷�ӵ������ĩβ����� index �ȳ��ȸ��󣬸ýڵ㽫������뵽�����С�
void deleteAtIndex(int index) ����±���Ч����ɾ���������±�Ϊ index �Ľڵ㡣
*/

//������
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}//�ڵ㹹�캯��
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
private:
    int size;
    ListNode* dummyHead;
public:
    MyLinkedList() {
        size = 0;
        dummyHead = new ListNode(0);
    }

    int get(int index) {
        if (index > size - 1 || index < 0) {
            return -1;
        }
        ListNode* cur = dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;//�����µ�ͷ�ڵ�
        size++;//�ڵ������һ

    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while (cur->next) {
            cur = cur->next;
        }//���������һ�����յĽڵ㣬Ȼ���ٽ����½ڵ�
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;// ���index��������ĳ��ȣ��򷵻ؿ�
        if (index < 0) index = 0;// ���indexС��0������ͷ������ڵ�
        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;//�����½ڵ㣬����������˳���ܻ�
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        ListNode* cur = dummyHead;
        while (index--) {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }

    void printLinkedList() {
        ListNode* cur = dummyHead->next;
        while (cur) {
            cout << cur->val;
            if (cur->next) {//�ж�ʱ�������һ���ڵ㣬��������һ���ڵ㣬next�ǿվͲ������ͷ
                cout << " -> ";
            }
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // �����Ϊ 1->2->3
    myLinkedList.get(1);              // ���� 2
    myLinkedList.deleteAtIndex(1);    // ���ڣ������Ϊ 1->3
    myLinkedList.get(1);              // ���� 3
    myLinkedList.printLinkedList();

    return 0;
}