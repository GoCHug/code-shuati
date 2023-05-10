#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};

int main() {
    vector<char> s = { 'h', 'e', 'l', 'l', 'o'};
    Solution so;
    so.reverseString(s);
    for (char& c : s) {
        cout << c;
    }
    cout << endl;

    system("pause");

    return 0;
}

