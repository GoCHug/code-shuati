#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {//遇到空格就删除掉
                if (slow != 0) s[slow++] = ' ';//除了第一个单词 加空格
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        int n = s.size();
        reverse(s, 0, n - 1);
        int start = 0;
        for (int i = 0; i <= n; i++) {
            if (s[i] == ' ' || s[i] == '\n') {
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
    string res =  so.reverseWords(s);
    cout << res;

    return 0;
}