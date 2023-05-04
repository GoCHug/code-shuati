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
            if (--record[c - 'a'] < 0) return false;//�Ѿ��ж��˳�������� ����aaac aacc a�������0 ��c����϶�С��0
        }
        return true;//ȫ�������궼û��С��0��˵������λ��
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
