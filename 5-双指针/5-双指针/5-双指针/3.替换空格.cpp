#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;//记录空格数量
        int old_size = s.size();
        for (char& c : s) {
            if (c == ' ') count++;
        }
        s.resize(old_size + 2 * count);
        int new_size = s.size();
        for (int i = old_size, j = new_size; i < j; i--, j--) {
            if (s[i] != ' ') {
                s[j] = s[i];
            }
            else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};

int main() {
    string s = "We are happy.";
    Solution so;
    string res = so.replaceSpace(s);
    cout << res;
    return 0;
}