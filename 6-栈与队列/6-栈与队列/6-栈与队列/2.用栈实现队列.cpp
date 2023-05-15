#include <iostream>
#include <stack>

using namespace std;

//使用栈来模式队列的行为，如果仅仅用一个栈，是一定不行的，
//需要两个栈一个输入栈，一个输出栈，这里要注意输入栈和输出栈的关系

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    //在push数据的时候，只要数据放进输入栈就好
    void push(int x) {
        stIn.push(x);
    }
    //在pop的时候，输出栈如果为空，1.把进栈数据全部导入进来，2.再从出栈弹出数据，
    //如果输出栈不为空，1.则直接从出栈弹出数据
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
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
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