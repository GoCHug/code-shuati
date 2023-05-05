#include <iostream>

using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end) {//×ó±ÕÓÒ±Õ
        int left = start;
        int right = end;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
            }
            else {
                reverse(s, i, s.size() - 1);
            }
        }
        return s;
    }
};

int main() {
    string s = "hello";
    int k = 3;
    cout << s << endl;

    Solution so;
    string res = so.reverseStr(s, 3);

    cout << res;
    return 0;
}