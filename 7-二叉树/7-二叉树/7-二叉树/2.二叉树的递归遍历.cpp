#include <iostream>
#include <vector>

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
	////前序遍历
	//void traversal(TreeNode* cur, vector<int>& res) {
	//	if (cur == NULL) return;
	//	res.push_back(cur->val);
	//	traversal(cur->left, res);
	//	traversal(cur->right, res);
	//}

	////中序遍历
	//void traversal(TreeNode* cur, vector<int>& res) {
	//	if (cur == NULL) return;
	//	traversal(cur->left, res);
	//	res.push_back(cur->val);
	//	traversal(cur->right, res);
	//}

	//后序遍历
	void traversal(TreeNode* cur, vector<int>& res) {
		if (cur == NULL) return;
		traversal(cur->left, res);
		traversal(cur->right, res);
		res.push_back(cur->val);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		traversal(root, res);
		return res;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution so;
	vector<int> res = so.preorderTraversal(root);
	for (int& x : res) {
		cout << x << " ";
	}

	return 0;
}