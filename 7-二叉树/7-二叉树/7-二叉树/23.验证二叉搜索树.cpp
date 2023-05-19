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
    ////递归法
    //long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
    //bool isValidBST(TreeNode* root) {
    //    if (root == NULL) return true;

    //    bool left = isValidBST(root->left);
    //    // 中序遍历，验证遍历的元素是不是从小到大
    //    if (maxVal < root->val) maxVal = root->val;
    //    else return false;
    //    bool right = isValidBST(root->right);

    //    return left && right;
    //}
    ////递归法 避免初始化最小值
    //TreeNode* pre = NULL; // 用来记录前一个节点
    //bool isValidBST(TreeNode* root) {
    //    if (root == NULL) return true;
    //    bool left = isValidBST(root->left);

    //    if (pre != NULL && pre->val >= root->val) return false;
    //    pre = root; // 记录前一个节点

    //    bool right = isValidBST(root->right);
    //    return left && right;
    //}

    //迭代法
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL; // 记录前一个节点
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;                // 左
            }
            else {
                cur = st.top();                 // 中
                st.pop();
                if (pre != NULL && cur->val <= pre->val)
                    return false;
                pre = cur; //保存前一个访问的结点

                cur = cur->right;               // 右
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
