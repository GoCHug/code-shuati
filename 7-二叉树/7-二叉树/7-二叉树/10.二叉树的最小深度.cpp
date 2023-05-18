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
	//递归法 后序
	int getHeight(TreeNode* node) {
		//终止条件
		if (node == NULL) return 0;

		//单层递归逻辑
		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);
		if (node->left == NULL && node->right != NULL) return 1 + rightHeight;
		else if (node->left != NULL && node->right == NULL) return 1 + leftHeight;
		return 1 + min(leftHeight, rightHeight);//左右都为空返回就是1+0
	}
	int minDepth(TreeNode* root) {
		return getHeight(root);
	}


	//迭代法 层序 当左右孩子都为空的时候，才说明遍历到最低点了
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++; // 记录最小深度
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
				if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
					return depth;
				}
			}
		}
		return depth;
	}
};


int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(4);

	Solution so;
	int res = so.minDepth(root);

	cout << res;
	return 0;
}