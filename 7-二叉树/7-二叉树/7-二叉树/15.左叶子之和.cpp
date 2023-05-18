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
	
	////�ݹ鷨
	//int sumOfLeftLeaves(TreeNode* root) {
	//	//��ֹ���� ֻ�е�ǰ�����Ľڵ��Ǹ��ڵ㣬�����ж����ӽڵ��ǲ�����Ҷ�ӡ� 
	//	//���������ǰ�����Ľڵ���Ҷ�ӽڵ㣬������Ҷ��Ҳ�ض���0
	//	if (root == NULL) return 0;
	//	if (root->left == NULL && root->right == NULL) return 0; //��ʵ���Ҳ���Բ�д�������д��Ӱ���������ͻ��õݹ�������һ�㡣

	//	//�����߼�
	//	int leftValue = sumOfLeftLeaves(root->left);    // ��
	//	if (root->left && !root->left->left && !root->left->right) {
	//		leftValue = root->left->val;
	//	}
	//	int rightValue = sumOfLeftLeaves(root->right);  // ��

	//	int sum = leftValue + rightValue;               // ��
	//	return sum;

	//}

	//������
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		stack<TreeNode*> st;
		st.push(root);
		int res = 0;
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			if (node->left && !node->left->left && !node->left->right) {
				res += node->left->val;
			}
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
		}
		return res;
	}
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
	int res = so.sumOfLeftLeaves(root);

	cout << res;

	return 0;
}
