#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // ��indexָ�������תΪint
        string letters = letterMap[digit];      // ȡ���ֶ�Ӧ���ַ���
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // ����
            backtracking(digits, index + 1);    // �ݹ飬ע��index+1��һ�²�Ҫ������һ��������
            s.pop_back();                       // ����
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};

int main() {
    string digits = "23";
    Solution so;
    vector<string> res = so.letterCombinations(digits);

    for (auto& s : res) {
        cout << s << " ";
    }
    return 0;
}