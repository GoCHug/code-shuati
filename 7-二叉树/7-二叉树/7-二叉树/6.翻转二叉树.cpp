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
    TreeNode* invertTree(TreeNode* root) {
		////递归法
		//if (root == NULL) return root;
		////因为是先前序遍历，所以先进行交换左右孩子节点，然后反转左子树，反转右子树。
		////后序也行，中序不行。使用递归的中序遍历，某些节点的左右孩子会翻转两次。
		//swap(root->left, root->right);
		//invertTree(root->left);
		//invertTree(root->right);
		//return root;

		////迭代法（前序遍历）
		//stack<TreeNode*> st;
		//if (root != NULL) st.push(root);
		//while (!st.empty()) {
		//	TreeNode* node = st.top();				//中
		//	st.pop();
		//	swap(node->left, node->right);
		//	if (node->right) st.push(node->right);	//右
		//	if (node->left) st.push(node->left);	//左
		//}
		//return root;

		////迭代统一法（前序遍历）
		//stack<TreeNode*> st;
		//if (root != NULL) st.push(root);
		//while (!st.empty()) {
		//	TreeNode* node = st.top();
		//	if (node != NULL) {
		//		st.pop();
		//		if (node->right) st.push(node->right);  // 右
		//		if (node->left) st.push(node->left);    // 左
		//		st.push(node);                          // 中
		//		st.push(NULL);
		//	}
		//	else {
		//		st.pop();
		//		node = st.top();
		//		st.pop();
		//		swap(node->left, node->right);          // 节点处理逻辑
		//	}
		//}
		//return root;

		//层序
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				swap(node->left, node->right); // 节点处理
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return root;



    }


	//层序遍历打印输出
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
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(4);
	Solution so;
	TreeNode* resRoot = so.invertTree(root);

	vector<vector<int>> res = so.levelOrder(resRoot);

	for (auto& x : res) {
		for (int& t : x) {
			cout << t << " ";
		}
		cout << endl;
	}
	return 0;
}