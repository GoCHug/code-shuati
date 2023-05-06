#include <iostream>

using namespace std;

class Solution {
public:
    // 反转字符串s中左闭右闭的区间[start, end]
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseLeftWords(string s, int n) {
        reverse(s, 0, s.size() - 1);
        reverse(s, 0, s.size() - n - 1);
        reverse(s, s.size() - n, s.size() - 1);
        return s;
    }

    ////使用reverse库函数是左闭右开的
    //string reverseLeftWords(string s, int n) {
    //    reverse(s.begin(), s.begin() + n);
    //    reverse(s.begin() + n, s.end());
    //    reverse(s.begin(), s.end());
    //    return s;
    //}
};

int main() {
    string s = "abcdefg";
    int n = 2;

    Solution so;
    s = so.reverseLeftWords(s, n);
    cout << s;
    return 0;
}