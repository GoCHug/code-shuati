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
	////�ݹ鷨
	//bool compare(TreeNode* left, TreeNode* right) {
	//	if (left != NULL && right == NULL) return false;
	//	else if (left == NULL && right != NULL) return false;
	//	else if (left == NULL && right == NULL) return true;
	//	else if (left->val != right->val) return false;

	//	//��ʱ�������ҽڵ㶼���գ�����ֵ��ͬ�����
	//	bool outside = compare(left->left, right->right);
	//	bool inside = compare(left->right, right->left);
	//	bool isSame = outside && inside;
	//	return isSame;
	//}
	//bool isSymmetric(TreeNode* root) {
	//	if (root == NULL) return true;
	//	return compare(root->left, root->right);
	//}

	////��������ʹ�ö��У�
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

	//		que.push(leftNode->left);   // ������ڵ�����
	//		que.push(rightNode->right); // �����ҽڵ��Һ���
	//		que.push(leftNode->right);  // ������ڵ��Һ���
	//		que.push(rightNode->left);  // �����ҽڵ�����
	//	}
	//	return true;
	//}


	// ��������ʵ�ǰ�������������Ҫ�Ƚϵ�Ԫ��˳��Ž�һ������,
	// Ȼ��ɶԳɶԵ�ȡ�������бȽ�,��ʵʹ��ջҲ�ǿ��Եġ�
	// ��������ʹ��ջ��
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

			st.push(leftNode->left);   // ������ڵ�����
			st.push(rightNode->right); // �����ҽڵ��Һ���
			st.push(leftNode->right);  // ������ڵ��Һ���
			st.push(rightNode->left);  // �����ҽڵ�����
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