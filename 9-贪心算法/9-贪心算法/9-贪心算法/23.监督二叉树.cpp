#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

/*
��������Ҫ�������Ͽ����ֲ����ţ���Ҷ�ӽڵ�ĸ��ڵ㰲����ͷ����������ͷ���٣�
�������ţ�ȫ������ͷ�����������٣�
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int result;
    int traversal(TreeNode* cur) {

        // �սڵ㣬�ýڵ��и���
        if (cur == NULL) return 2;

        int left = traversal(cur->left);    // ��
        int right = traversal(cur->right);  // ��

        // ���1
        // ���ҽڵ㶼�и���
        if (left == 2 && right == 2) return 0;

        // ���2
        // left == 0 && right == 0 ���ҽڵ��޸���
        // left == 1 && right == 0 ��ڵ�������ͷ���ҽڵ��޸���
        // left == 0 && right == 1 ��ڵ����޸��ǣ��ҽڵ�����ͷ
        // left == 0 && right == 2 ��ڵ��޸��ǣ��ҽڵ㸲��
        // left == 2 && right == 0 ��ڵ㸲�ǣ��ҽڵ��޸���
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }

        // ���3
        // left == 1 && right == 2 ��ڵ�������ͷ���ҽڵ��и���
        // left == 2 && right == 1 ��ڵ��и��ǣ��ҽڵ�������ͷ
        // left == 1 && right == 1 ���ҽڵ㶼������ͷ
        // �������ǰ�δ�����Ѹ���
        if (left == 1 || right == 1) return 2;

        // ���ϴ�����û��ʹ��else����Ҫ��Ϊ�˰Ѹ�����֧����չ�ֳ������������������ڶ������
        // ��� return -1 �߼������ߵ����
        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        // ���4
        if (traversal(root) == 0) { // root �޸���
            result++;
        }
        return result;
    }
};

int main() {
    TreeNode* node = new TreeNode(0);
    node->left = new TreeNode(0);
    node->left->left = new TreeNode(0);
    node->left->right = new TreeNode(0);

    Solution so;
    int res = so.minCameraCover(node);

    cout << res;
    return 0;
}