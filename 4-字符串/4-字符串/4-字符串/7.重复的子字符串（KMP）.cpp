#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getNext(vector<int>& next, const string& s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        vector<int> next(s.size());
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) {
            return true;//数组的长度正好可以被 (数组长度-最长相等前后缀的长度) 整除，说明该字符串有重复的子字符串。
        }
        return false;
    }
};

int main() {

    return 0;
}