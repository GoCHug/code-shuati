#include <iostream>

using namespace std;

/*
˼·��
�Ƴ�����ո� �������ַ�����ת ��ÿ�����ʷ�ת
*/

class Solution {
public:
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); ++fast) {//���˿ո�
            if (s[fast] != ' ') {
                if (slow != 0) s[slow++] = ' ';//�����ǿո�ĵ����ȼӸ��ո񣬵�һ������ǰ���ӿո�
                while (fast < s.size() && s[fast] != ' ') {//��ֵ�������ֱ�������ո�
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    // ��ת�ַ���s������ұյ�����[start, end]
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {//ע�⣡��������i <= s.size()�еȺţ���Ҫ��ת���һ������
            if (s[i] == ' ' || s[i] == '\0') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

int main() {
    string s = "the sky is blue";

    Solution so;
    s = so.reverseWords(s);
    cout << s;
    return 0;
}