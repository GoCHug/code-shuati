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
	//递归法
	//如果使用递归法，如何判断是最后一行呢，其实就是深度最大的叶子节点一定是最后一行。
	int maxDepth = INT_MIN;   // 全局变量 记录最大深度
	int result;       // 全局变量 最大深度最左节点的数值
	void traversal(TreeNode* root, int depth) {
		//终止条件
		if (root->left == NULL && root->right == NULL) {
			if (depth > maxDepth) {
				maxDepth = depth;
				result = root->val;
			}
			return;
		}
		//单层逻辑
		if (root->left) {
			depth++;
			traversal(root->left, depth);
			depth--; // 回溯
		}
		if (root->right) {
			depth++;
			traversal(root->right, depth);
			depth--; // 回溯
		}
		return;
	}
	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 1);
		return result;
	}


	////迭代法 层序遍历 只需要记录最后一行第一个节点的数值就可以了
	//int findBottomLeftValue(TreeNode* root) {
	//	queue<TreeNode*> que;
	//	if (root != NULL) que.push(root);
	//	int res = 0;
	//	while (!que.empty()) {
	//		int size = que.size();
	//		for (int i = 0; i < size; i++) {
	//			TreeNode* node = que.front();
	//			que.pop();
	//			if (i == 0) res = node->val;// 记录最后一行第一个元素
	//			if (node->left) que.push(node->left);
	//			if (node->right) que.push(node->right);
	//		}
	//	}
	//	return res;
	//}
};


int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->left->right->left = new TreeNode(8);

	Solution so;
	int res = so.findBottomLeftValue(root);

	cout << res;

	return 0;
}
