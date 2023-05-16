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
		stack<TreeNode*> st;
		vector<int> res;
		if (root == NULL) return res; //如果栈不空 就弹出栈顶元素处理，再压入右节点 左节点
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			res.push_back(node->val);
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
		}
		return res;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty()) {//cur为空&&栈为空 同时为空表示遍历结束
			if (cur != NULL) {//一直向左走
				st.push(cur);
				cur = cur->left;					// 左
			}
			else {//遇到空节点了，从栈里弹出节点
				cur = st.top();// 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
				st.pop();
				res.push_back(cur->val);	// 中
				cur = cur->right;			// 右
			}
		}
		return res;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> res;
		if (root == NULL) return res;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			res.push_back(node->val);
			if (node->left) st.push(node->left);
			if (node->right) st.push(node->right);
		}
		reverse(res.begin(), res.end()); // 将结果反转之后就是左右中的顺序了
		return res;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution so;
	//vector<int> res = so.preorderTraversal(root);
	vector<int> res = so.inorderTraversal(root);
	//vector<int> res = so.postorderTraversal(root);

	
	for (int& x : res) {
		cout << x << " ";
	}

	return 0;
}