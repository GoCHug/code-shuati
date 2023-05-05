#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < oldSize; ++i) {
            if (s[i] == ' ') count++;
        }//统计空格个数

        s.resize(oldSize + 2 * count);//扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        int newSize = s.size();
        //从后往前遍历使用双指针法
        for (int i = newSize, j = oldSize; j < i; i--, j--) {//注意 循环条件j < i
            if (s[j] != ' ') {
                s[i] = s[j];
            }
            else {//等于空格时
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