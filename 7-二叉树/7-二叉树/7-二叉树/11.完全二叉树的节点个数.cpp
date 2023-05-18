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
	////普通二叉树解法
	//int getNum(TreeNode* node) {
	//	if (node == NULL) return 0;

	//	int leftNum = getNum(node->left);
	//	int rightNum = getNum(node->right);
	//	int treeNum = 1 + leftNum + rightNum;
	//	return treeNum;
	//}
	//int countNodes(TreeNode* root) {
	//	return getNum(root);
	//}
	////普通二叉树迭代法 层序
	//int countNodes(TreeNode* root) {
	//	queue<TreeNode*> que;
	//	if (root != NULL) que.push(root);
	//	int result = 0;
	//	while (!que.empty()) {
	//		int size = que.size();
	//		for (int i = 0; i < size; i++) {
	//			TreeNode* node = que.front();
	//			que.pop();
	//			result++;   // 记录节点数量
	//			if (node->left) que.push(node->left);
	//			if (node->right) que.push(node->right);
	//		}
	//	}
	//	return result;
	//}

	//完全二叉树解法
	int getNum(TreeNode* node) {
		if (node == NULL) return 0;
		// 终止条件 满二叉树
		// 开始根据左深度和右深度是否相同来判断该子树是不是满二叉树
		TreeNode* left = node->left;
		TreeNode* right = node->right;
		int leftNum = 0, rightNum = 0;// 这里初始为0是有目的的，为了下面求指数方便
		while (left) {
			leftNum++;
			left = left->left;
		}
		while (right) {
			rightNum++;
			right = right->right;
		}
		if (leftNum == rightNum) {
			return (2 << leftNum) - 1;// 注意(2<<1) 相当于2^2，返回满足满二叉树的子树节点数量
		}

		//单层递归逻辑
		int leftTreeNum = getNum(node->left);			//左
		int rightTreeNum = getNum(node->right);			//右
		int resNum = 1 + leftTreeNum + rightTreeNum;	//中
		return resNum;
	}
	int countNodes(TreeNode* root) {
		return getNum(root);
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
	int res = so.countNodes(root);

	cout << res;
	return 0;
}