#include <iostream>
#include <vector>
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if (root) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
				if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

				if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）

				st.push(node);                          // 添加中节点
				st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。
			}
			else {// 只有遇到空节点的时候，才将下一个节点放进结果集
				st.pop();           // 将空节点弹出
				node = st.top();    // 重新取出栈中元素
				st.pop();
				res.push_back(node->val); // 加入到结果集
			}
		}
		return res;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if (root) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
				if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

				st.push(node);                          // 添加中节点
				st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

				if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
			}
			else {// 只有遇到空节点的时候，才将下一个节点放进结果集
				st.pop();           // 将空节点弹出
				node = st.top();    // 重新取出栈中元素
				st.pop();
				res.push_back(node->val); // 加入到结果集
			}
		}
		return res;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if (root) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
				st.push(node);                          // 添加中节点
				st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

				if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

				if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
			}
			else {// 只有遇到空节点的时候，才将下一个节点放进结果集
				st.pop();           // 将空节点弹出
				node = st.top();    // 重新取出栈中元素
				st.pop();
				res.push_back(node->val); // 加入到结果集
			}
		}
		return res;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution so;
	//vector<int> res = so.preorderTraversal(root);
	//vector<int> res = so.inorderTraversal(root);
	vector<int> res = so.postorderTraversal(root);


	for (int& x : res) {
		cout << x << " ";
	}

	return 0;
}