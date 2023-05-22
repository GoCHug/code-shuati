#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(string s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};

int main() {
    string s = "aab";

    Solution so;
    vector<vector<string>> res = so.partition(s);

    for (vector<string>& vec : res) {
        for (string& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}