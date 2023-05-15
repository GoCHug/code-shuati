#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 力扣修改了后台测试数据，需要用longlong
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
        st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
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