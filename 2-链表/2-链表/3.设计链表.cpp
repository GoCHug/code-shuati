#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/*
单链表中的节点应该具备两个属性：val 和 next。

假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 - 1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将不会插入到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
*/

//链表定义
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}//节点构造函数
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
        dummyHead->next = newNode;//更新新的头节点
        size++;//节点个数加一

    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while (cur->next) {
            cur = cur->next;
        }//遍历到最后一个不空的节点，然后再接上新节点
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;// 如果index大于链表的长度，则返回空
        if (index < 0) index = 0;// 如果index小于0，则在头部插入节点
        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;//接入新节点，这两个步骤顺序不能换
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
            if (cur->next) {//判断时候是最后一个节点，如果是最后一个节点，next是空就不输出箭头
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
    myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
    myLinkedList.get(1);              // 返回 2
    myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
    myLinkedList.get(1);              // 返回 3
    myLinkedList.printLinkedList();

    return 0;
}