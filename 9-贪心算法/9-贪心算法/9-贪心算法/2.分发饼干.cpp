#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] > g[i]) {
                index--;
                result++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> g = { 1, 2 };
    vector<int> s = { 1, 2, 3 };

    Solution so;
    int res = so.findContentChildren(g, s);

    cout << res;
    return 0;
}