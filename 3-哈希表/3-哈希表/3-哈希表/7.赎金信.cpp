#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        vector<int> record(26);//当题目限制了数值的大小的时候，考虑用数组
        for (char& c : magazine) {
            record[c - 'a']++;
        }
        for (char& c : ransomNote) {
            if (--record[c - 'a'] < 0) return false;
        }
        return true;
    }
};

int main() {
    string ransomNote = "aa";
    string magazine = "aab";

    Solution so;
    bool res = so.canConstruct(ransomNote, magazine);
    cout << res;
    return 0;
}