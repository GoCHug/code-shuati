#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> que;
    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;//�������һ��Ԫ�� ��ѭ��������β
        while (size--) {
            que.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.pop();
        return res;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }

    void printS() {
        cout << "��ջ����ջ��" << endl;
        while (!this->empty()) {
            cout << this->pop() << " ";
        }
    }
};

int main() {
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.top();
    myStack.pop();
    myStack.empty(); // ���� False

    myStack.printS();
    return 0;
}
