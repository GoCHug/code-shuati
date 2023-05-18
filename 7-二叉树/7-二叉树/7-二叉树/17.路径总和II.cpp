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
private:
    void traversal(TreeNode* cur, int count, vector<int>& path, vector<vector<int>>& result) {

        if (!cur->left && !cur->right && count == 0) { // 遇到了叶子节点且找到了和为sum的路径
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right) return; // 遇到叶子节点而没有找到合适的边，直接返回

        if (cur->left) { // 左 （空节点不遍历）
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count, path, result);    // 递归
            count += cur->left->val;        // 回溯
            path.pop_back();                // 回溯
        }
        if (cur->right) { // 右 （空节点不遍历）
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count, path, result);   // 递归
            count += cur->right->val;       // 回溯
            path.pop_back();                // 回溯
        }
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        if (root == NULL) return result;
        path.push_back(root->val); // 把根节点放进路径
        traversal(root, sum - root->val, path, result);
        return result;
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);

    Solution so;
    int sum = 7;
    vector<vector<int>> res = so.pathSum(root, sum);

    for (auto& x : res) {
        for (auto& t : x) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
