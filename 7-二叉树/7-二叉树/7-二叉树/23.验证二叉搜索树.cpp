#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    ////�ݹ鷨
    //long long maxVal = LONG_MIN; // ��Ϊ��̨������������int��Сֵ
    //bool isValidBST(TreeNode* root) {
    //    if (root == NULL) return true;

    //    bool left = isValidBST(root->left);
    //    // �����������֤������Ԫ���ǲ��Ǵ�С����
    //    if (maxVal < root->val) maxVal = root->val;
    //    else return false;
    //    bool right = isValidBST(root->right);

    //    return left && right;
    //}
    ////�ݹ鷨 �����ʼ����Сֵ
    //TreeNode* pre = NULL; // ������¼ǰһ���ڵ�
    //bool isValidBST(TreeNode* root) {
    //    if (root == NULL) return true;
    //    bool left = isValidBST(root->left);

    //    if (pre != NULL && pre->val >= root->val) return false;
    //    pre = root; // ��¼ǰһ���ڵ�

    //    bool right = isValidBST(root->right);
    //    return left && right;
    //}

    //������
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL; // ��¼ǰһ���ڵ�
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;                // ��
            }
            else {
                cur = st.top();                 // ��
                st.pop();
                if (pre != NULL && cur->val <= pre->val)
                    return false;
                pre = cur; //����ǰһ�����ʵĽ��

                cur = cur->right;               // ��
            }
        }
        return true;
    }
};


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;

    Solution so;
    bool res = so.isValidBST(root);

    cout << res;
    return 0;
}
