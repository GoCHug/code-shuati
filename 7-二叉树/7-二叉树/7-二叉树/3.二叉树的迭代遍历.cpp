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
		if (root == NULL) return res; //���ջ���� �͵���ջ��Ԫ�ش�����ѹ���ҽڵ� ��ڵ�
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
		while (cur != NULL || !st.empty()) {//curΪ��&&ջΪ�� ͬʱΪ�ձ�ʾ��������
			if (cur != NULL) {//һֱ������
				st.push(cur);
				cur = cur->left;					// ��
			}
			else {//�����սڵ��ˣ���ջ�ﵯ���ڵ�
				cur = st.top();// ��ջ�ﵯ�������ݣ�����Ҫ��������ݣ��Ž�result����������ݣ�
				st.pop();
				res.push_back(cur->val);	// ��
				cur = cur->right;			// ��
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
		reverse(res.begin(), res.end()); // �������ת֮����������е�˳����
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