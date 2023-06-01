#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

//����98��һ������strNum[i - 1] > strNum[i]��������ǵ�������������������strNum[i - 1]��һ��strNum[i]��ֵ9�����������������89��
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag������Ǹ�ֵ9�����￪ʼ
        // ����Ϊ���Ĭ��ֵ��Ϊ�˷�ֹ�ڶ���forѭ����flagû�б���ֵ�������ִ��
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                flag = i;
                strNum[i - 1]--;//ֻҪ�Ķ��˸�λ�������λȫ��9
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};

int main() {
    int n = 33232542;
    Solution so;
    int res = so.monotoneIncreasingDigits(n);

    cout << res; 
    return 0;
}