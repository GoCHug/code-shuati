#include <iostream>
#include <stack>

using namespace std;

/*
��������һ�� ���������ֲ�ƥ��������
��һ��������ַ�������������Ŷ����ˣ����Բ�ƥ�䡣
�ڶ������������û�ж��࣬�������ŵ�����û��ƥ���ϡ�
������������ַ������ҷ�������Ŷ����ˣ����Բ�ƥ�䡣
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
            // ����������������ַ���ƥ��Ĺ����У�ջ�Ѿ�Ϊ���ˣ�û��ƥ����ַ��ˣ�˵��������û���ҵ���Ӧ�������� return false
            // �ڶ�������������ַ���ƥ��Ĺ����У�����ջ��û������Ҫƥ����ַ�������return false
            else if (stk.empty() || c != stk.top()) {
                return false;
            }
            else if (c == stk.top()) {// st.top() �� s[i]��ȣ�ջ����Ԫ��
                stk.pop();
            }
        }
        // ��һ��������������ַ���������ջ��Ϊ�գ�
        //˵������Ӧ��������û����������ƥ�䣬����return false�������return true
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