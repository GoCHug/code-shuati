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
            return true;//����ĳ������ÿ��Ա� (���鳤��-����ǰ��׺�ĳ���) ������˵�����ַ������ظ������ַ�����
        }
        return false;
    }
};

int main() {

    return 0;
}