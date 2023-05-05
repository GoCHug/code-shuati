#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < oldSize; ++i) {
            if (s[i] == ' ') count++;
        }//ͳ�ƿո����

        s.resize(oldSize + 2 * count);//�����ַ���s�Ĵ�С��Ҳ����ÿ���ո��滻��"%20"֮��Ĵ�С
        int newSize = s.size();
        //�Ӻ���ǰ����ʹ��˫ָ�뷨
        for (int i = newSize, j = oldSize; j < i; i--, j--) {//ע�� ѭ������j < i
            if (s[j] != ' ') {
                s[i] = s[j];
            }
            else {//���ڿո�ʱ
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

int main() {
    string s = "We are happy.";
    cout << s << endl;

    Solution so;
    string res = so.replaceSpace(s);

    cout << res;
    return 0;
}