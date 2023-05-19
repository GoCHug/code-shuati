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

//class Solution {
//private:
//    int result = INT_MAX;
//    TreeNode* pre = NULL;
//    void traversal(TreeNode* cur) {
//        if (cur == NULL) return;
//        traversal(cur->left);   // 左
//        if (pre != NULL) {       // 中
//            result = min(result, cur->val - pre->val);
//        }
//        pre = cur; // 记录前一个
//        traversal(cur->right);  // 右
//    }
//public:
//    int getMinimumDifference(TreeNode* root) {
//        traversal(root);
//        return result;
//    }
//};

//迭代法 中序
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int result = INT_MAX;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            }
            else {
                cur = st.top();
                st.pop();
                if (pre != NULL) {              // 中
                    result = min(result, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;               // 右
            }
        }
        return result;
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
    bool res = so.getMinimumDifference(root);

    cout << res;
    return 0;
}
