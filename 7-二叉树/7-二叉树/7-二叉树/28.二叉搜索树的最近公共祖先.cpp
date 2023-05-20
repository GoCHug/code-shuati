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
    ////��������ȥ�ݹ��������һ������ cur�ڵ�����ֵ��[p, q]�����У���ôcur���� p��q�������������
    //TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //    if (root == NULL) return root;

    //    if (root->val > p->val && root->val > q->val) {   // ��
    //        TreeNode* left = lowestCommonAncestor(root->left, p, q);
    //        if (left != NULL) {
    //            return left;
    //        }
    //    }
    //    if (root->val < p->val && root->val < q->val) {   // ��
    //        TreeNode* right = lowestCommonAncestor(root->right, p, q);
    //        if (right != NULL) {
    //            return right;
    //        }
    //    }
    //    return root;
    //}

    //������
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            else return root;
        }
        return NULL;
    }
};


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* p = root->left;
    TreeNode* q = root->right;
    Solution so;
    TreeNode* res = so.lowestCommonAncestor(root, p, q);
    cout << res->val;

    return 0;
}
