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
	////递归法
	//bool compare(TreeNode* left, TreeNode* right) {
	//	if (left != NULL && right == NULL) return false;
	//	else if (left == NULL && right != NULL) return false;
	//	else if (left == NULL && right == NULL) return true;
	//	else if (left->val != right->val) return false;

	//	//此时就是左右节点都不空，且数值相同的情况
	//	bool outside = compare(left->left, right->right);
	//	bool inside = compare(left->right, right->left);
	//	bool isSame = outside && inside;
	//	return isSame;
	//}
	//bool isSymmetric(TreeNode* root) {
	//	if (root == NULL) return true;
	//	return compare(root->left, root->right);
	//}

	////迭代法（使用队列）
	//bool isSymmetric(TreeNode* root) {
	//	if (root == NULL) return true;
	//	queue<TreeNode*> que;
	//	que.push(root->left);
	//	que.push(root->right);
	//	while (!que.empty()) {
	//		TreeNode* leftNode = que.front(); que.pop();
	//		TreeNode* rightNode = que.front(); que.pop();

	//		if (leftNode != NULL && rightNode == NULL) return false;
	//		else if (leftNode == NULL && rightNode != NULL) return false;
	//		else if (leftNode == NULL && rightNode == NULL) continue;
	//		else if (leftNode->val != rightNode->val) return false;

	//		que.push(leftNode->left);   // 加入左节点左孩子
	//		que.push(rightNode->right); // 加入右节点右孩子
	//		que.push(leftNode->right);  // 加入左节点右孩子
	//		que.push(rightNode->left);  // 加入右节点左孩子
	//	}
	//	return true;
	//}


	// 迭代法其实是把左右两个子树要比较的元素顺序放进一个容器,
	// 然后成对成对的取出来进行比较,其实使用栈也是可以的。
	// 迭代法（使用栈）
		bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		stack<TreeNode*> st;
		st.push(root->left);
		st.push(root->right);
		while (!st.empty()) {
			TreeNode* leftNode = st.top(); st.pop();
			TreeNode* rightNode = st.top(); st.pop();

			if (leftNode != NULL && rightNode == NULL) return false;
			else if (leftNode == NULL && rightNode != NULL) return false;
			else if (leftNode == NULL && rightNode == NULL) continue;
			else if (leftNode->val != rightNode->val) return false;

			st.push(leftNode->left);   // 加入左节点左孩子
			st.push(rightNode->right); // 加入右节点右孩子
			st.push(leftNode->right);  // 加入左节点右孩子
			st.push(rightNode->left);  // 加入右节点左孩子
		}
		return true;
	}

};


int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->left->right = new TreeNode(3);

	Solution so;
	bool res = so.isSymmetric(root);

	cout << res;
	return 0;
}