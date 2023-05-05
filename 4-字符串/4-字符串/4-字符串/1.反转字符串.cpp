#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};


int main() {
    vector<char> s = {'h','e','l','l','o'};
    for (auto& c : s) {
        cout << c;
    }
    cout << endl;
    Solution so;
    so.reverseString(s);

    for (auto& c : s) {
        cout << c;
    }
	return 0;
}