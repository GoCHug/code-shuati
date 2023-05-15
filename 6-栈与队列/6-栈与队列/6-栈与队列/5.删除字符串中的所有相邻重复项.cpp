#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
    //    stack<char> stk;
    //    for (char& c : s) {
    //        if (!stk.empty() && c == stk.top()) {
    //            stk.pop();
    //        }
    //        else {
    //            stk.push(c);
    //        }
    //    }
    //    string res = "";
    //    while (!stk.empty()) {
    //        res += stk.top();
    //        stk.pop();
    //    }
    //    reverse(res.begin(), res.end());
    //    return res;

        string res;
        //法2：直接将字符串作为栈
        for (char& c : s) {
            if (res.empty() || c != res.back()) {
                res.push_back(c);
            }
            else {
                res.pop_back();
            }
        }
        return res;
    }
};

int main() {
    string s = "abbaca";
    Solution so;
    string res = so.removeDuplicates(s);
    cout << res;
    return 0;
}