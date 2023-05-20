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
    //迭代法
    TreeNode* deleteNode(TreeNode* root, int key) {
        /*
        终止条件 有以下五种情况：
        第一种情况：没找到删除的节点，遍历到空节点直接返回了
        找到删除的节点：
        第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
        第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
        第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
        第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树
        的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。
        */
        if (root == NULL) return NULL;//1
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {//2
                delete root;
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL) {//3
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
            else if (root->left != NULL && root->right == NULL) {//4
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            }
            else {//5
                TreeNode* cur = root->right;
                while (cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
        }

        //单层逻辑
        if (key < root->val) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }


    //层序遍历 打印输出用
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int key = 2;
    Solution so;
    TreeNode* node = so.deleteNode(root, key);
    //层序遍历打印输出
    vector<vector<int>> res = so.levelOrder(node);
    for (auto& x : res) {
        for (int& t : x) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
