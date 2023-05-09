#include <iostream>
#include <vector>

using namespace std;
/*
����nΪ�ı������ȣ�mΪģʽ�����ȣ���Ϊ��ƥ��Ĺ����У�����ǰ׺���ϵ���ƥ���λ�ã�
���Կ���ƥ��Ĺ�����O(n)��֮ǰ��Ҫ��������next���飬ʱ�临�Ӷ���O(m)��
��������KMP�㷨��ʱ�临�Ӷ���O(n+m)�ġ�
*/
//ʲô��ǰ׺����¼�±�i֮ǰ������i�����ַ����У��ж�󳤶ȵ���ͬǰ׺��׺
//ΪʲôҪǰһ���ַ���ǰ׺�����ֵ�أ���ΪҪ��ǰ���ַ��������ͬ��ǰ׺�ͺ�׺��
class Solution {
public:
    /*
    ���ڵ�ǰ��������i������ָ��i��j��jָ��ǰ׺ĩβλ�ã�iָ���׺ĩβλ��
    next[i] ��ʾ i������i��֮ǰ���ȵ�ǰ��׺���ȣ���ʵ����j��

    1.��ʼ��
    2.����ǰ��׺����ͬ�����
    3.����ǰ��׺��ͬ�����
    4.next�������
    */

    void getNext(vector<int>& next, const string& s) {//vector<int>& Ҫ�����ã�����
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); ++i) {//����ģʽ��s��ѭ���±�i Ҫ�� 1��ʼ
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            
            if (s[i] == s[j]) {
                j++;
            }

            next[i] = j;
        }

    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size());//����needle��С��next����
        getNext(next, needle);//��ֵnext����
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];// j Ѱ��֮ǰƥ���λ��
            }
            if (haystack[i] == needle[j]) {// ƥ�䣬j��iͬʱ����ƶ�
                j++;
            }
            if (j == needle.size()) {// �ı���haystack�������ģʽ��needle
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "mississippi";
    string needle = "issip";

    Solution so;
    int res = so.strStr(haystack, needle);
    cout << res;
    return 0;
}