#include <iostream>
#include <stack>

using namespace std;

//ʹ��ջ��ģʽ���е���Ϊ�����������һ��ջ����һ�����еģ�
//��Ҫ����ջһ������ջ��һ�����ջ������Ҫע������ջ�����ջ�Ĺ�ϵ

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    //��push���ݵ�ʱ��ֻҪ���ݷŽ�����ջ�ͺ�
    void push(int x) {
        stIn.push(x);
    }
    //��pop��ʱ�����ջ���Ϊ�գ�1.�ѽ�ջ����ȫ�����������2.�ٴӳ�ջ�������ݣ�
    //������ջ��Ϊ�գ�1.��ֱ�Ӵӳ�ջ��������
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }

    int peek() {
        int res = this->pop(); // ֱ��ʹ�����е�pop����
        stOut.push(res); // ��Ϊpop����������Ԫ��res����������ӻ�ȥ
        return res;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }

    void printQ() {
        while (!this->empty()) {
            cout << this->pop() << " ";
        }
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.peek();
    myQueue.pop();
    myQueue.empty();

    myQueue.printQ();
    return 0;
}