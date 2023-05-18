#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
	//递归 后序
	int getHeight(TreeNode* node) {
		if (node == NULL) return 0;

		int leftHeight = getHeight(node->left); // 左
		if (leftHeight == -1) return -1;
		int rightHeight = getHeight(node->right); // 右
		if (rightHeight == -1) return -1;

		int result;
		if (abs(leftHeight - rightHeight) > 1) {  // 中
			result = -1;
		}
		else {
			result = 1 + max(leftHeight, rightHeight); // 以当前节点为根节点的树的最大高度
		}

		return result;

	}

	bool isBalanced(TreeNode* root) {
		return getHeight(root) == -1 ? false : true;
	}
};


int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	Solution so;
	int res = so.isBalanced(root);

	cout << res;
	return 0;
}