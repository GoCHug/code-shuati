#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int>  record(26);
        for (char& c : s) {
            record[c - 'a']++;
        }
        for (char& c : t) {
            if (--record[c - 'a'] < 0) return false;//已经判断了长度相等了 比如aaac aacc a减完大于0 那c减完肯定小于0
        }
        return true;//全部遍历完都没有小于0的说明是异位词
    }
};

int main() {
    string s = "aee";
    string t = "eae";
    Solution so;
    bool res = so.isAnagram(s, t);
    cout << res;
	return 0;
}
