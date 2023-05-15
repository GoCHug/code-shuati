#include <iostream>
#include <stack>

using namespace std;

/*
先来分析一下 这里有三种不匹配的情况，
第一种情况，字符串里左方向的括号多余了，所以不匹配。
第二种情况，括号没有多余，但是括号的类型没有匹配上。
第三种情况，字符串里右方向的括号多余了，所以不匹配。
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;

        stack<char> stk;
        for (char& c : s) {
            if (c == '(') {
                stk.push(')');
            }
            else if (c == '{') {
                stk.push('}');
            }
            else if (c == '[') {
                stk.push(']');
            }
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (stk.empty() || c != stk.top()) {
                return false;
            }
            else if (c == stk.top()) {// st.top() 与 s[i]相等，栈弹出元素
                stk.pop();
            }
        }
        // 第一种情况：遍历完字符串，但是栈不为空，
        //说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return stk.empty();
    }
};

int main() {
    string s = "()[]{}";

    Solution so;
    bool res = so.isValid(s);
    cout << res;

    return 0;
}