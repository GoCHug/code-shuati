#include <iostream>
#include <vector>

using namespace std;
/*
其中n为文本串长度，m为模式串长度，因为在匹配的过程中，根据前缀表不断调整匹配的位置，
可以看出匹配的过程是O(n)，之前还要单独生成next数组，时间复杂度是O(m)。
所以整个KMP算法的时间复杂度是O(n+m)的。
*/
//什么是前缀表：记录下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀
//为什么要前一个字符的前缀表的数值呢，因为要找前面字符串的最长相同的前缀和后缀。
class Solution {
public:
    /*
    对于当前遍历到的i，两个指针i和j，j指向前缀末尾位置，i指向后缀末尾位置
    next[i] 表示 i（包括i）之前最长相等的前后缀长度（其实就是j）

    1.初始化
    2.处理前后缀不相同的情况
    3.处理前后缀相同的情况
    4.next数组更新
    */

    void getNext(vector<int>& next, const string& s) {//vector<int>& 要加引用！！！
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); ++i) {//遍历模式串s的循环下标i 要从 1开始
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
        vector<int> next(needle.size());//创建needle大小的next数组
        getNext(next, needle);//赋值next数组
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];// j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j]) {// 匹配，j和i同时向后移动
                j++;
            }
            if (j == needle.size()) {// 文本串haystack里出现了模式串needle
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