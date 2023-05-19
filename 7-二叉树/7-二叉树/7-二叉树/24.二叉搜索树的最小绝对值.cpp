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
//        traversal(cur->left);   // ��
//        if (pre != NULL) {       // ��
//            result = min(result, cur->val - pre->val);
//        }
//        pre = cur; // ��¼ǰһ��
//        traversal(cur->right);  // ��
//    }
//public:
//    int getMinimumDifference(TreeNode* root) {
//        traversal(root);
//        return result;
//    }
//};

//������ ����
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int result = INT_MAX;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // ָ�������ʽڵ㣬���ʵ���ײ�
                st.push(cur); // �����ʵĽڵ�Ž�ջ
                cur = cur->left;                // ��
            }
            else {
                cur = st.top();
                st.pop();
                if (pre != NULL) {              // ��
                    result = min(result, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;               // ��
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
