#include <iostream>

using namespace std;

/*
思路：
移除多余空格 将整个字符串反转 将每个单词反转
*/

class Solution {
public:
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); ++fast) {//过滤空格
            if (s[fast] != ' ') {
                if (slow != 0) s[slow++] = ' ';//遇到非空格的单词先加个空格，第一个单词前不加空格
                while (fast < s.size() && s[fast] != ' ') {//赋值这个单词直到遇到空格
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    // 反转字符串s中左闭右闭的区间[start, end]
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {//注意！！！这里i <= s.size()有等号，还要翻转最后一个单词
            if (s[i] == ' ' || s[i] == '\0') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

int main() {
    string s = "the sky is blue";

    Solution so;
    s = so.reverseWords(s);
    cout << s;
    return 0;
}