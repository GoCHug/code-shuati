#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // �����޸��˺�̨�������ݣ���Ҫ��longlong
        stack<long long> st;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                    if (s == "+") st.push(num2 + num1);
                    if (s == "-") st.push(num2 - num1);
                    if (s == "*") st.push(num2 * num1);
                    if (s == "/") st.push(num2 / num1);
            }
            else {
                st.push(stoll(s));
            }
        }
        int res = st.top();
        st.pop(); // ��ջ�����һ��Ԫ�ص�������ʵ������Ҳû�£�
        return res;

    }
};

int main() {
    vector<string> tokens = { "2", "1", "+", "3", "*" };
    Solution so;
    int res = so.evalRPN(tokens);
    cout << res;
    return 0;
}