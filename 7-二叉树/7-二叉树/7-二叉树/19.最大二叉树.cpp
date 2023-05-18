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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        int numMax = INT_MIN;
        int indexMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > numMax) {
                numMax = nums[i];
                indexMax = i;
            }
        }
        TreeNode* root = new TreeNode(numMax);
        
        vector<int> leftNums(nums.begin(), nums.begin() + indexMax);
        vector<int> rightNums(nums.begin() + indexMax + 1, nums.end());
        root->left = constructMaximumBinaryTree(leftNums);//因为前面判断了空的情况，这里不用再判断空了 if (nums.size() == 0) return NULL;
        root->right = constructMaximumBinaryTree(rightNums);
        //一般情况来说：如果让空节点（空指针）进入递归，就不加if，
        //如果不让空节点进入递归，就加if限制一下， 终止条件也会相应的调整。
        return root;
    }

    //层序遍历 打印输出
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
    vector<int> nums = { 3,2,1,6,0,5 };
    Solution so;
    TreeNode* root = so.constructMaximumBinaryTree(nums);

    //层序遍历打印输出
    vector<vector<int>> res = so.levelOrder(root);
    for (auto& x : res) {
        for (int& t : x) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
