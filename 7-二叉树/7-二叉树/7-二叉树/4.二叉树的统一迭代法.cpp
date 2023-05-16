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
				st.pop(); // ���ýڵ㵯���������ظ������������ٽ�������ڵ���ӵ�ջ��
				if (node->right) st.push(node->right);  // ����ҽڵ㣨�սڵ㲻��ջ��

				if (node->left) st.push(node->left);    // �����ڵ㣨�սڵ㲻��ջ��

				st.push(node);                          // ����нڵ�
				st.push(NULL); // �нڵ���ʹ������ǻ�û�д�������սڵ���Ϊ��ǡ�
			}
			else {// ֻ�������սڵ��ʱ�򣬲Ž���һ���ڵ�Ž������
				st.pop();           // ���սڵ㵯��
				node = st.top();    // ����ȡ��ջ��Ԫ��
				st.pop();
				res.push_back(node->val); // ���뵽�����
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
				st.pop(); // ���ýڵ㵯���������ظ������������ٽ�������ڵ���ӵ�ջ��
				if (node->right) st.push(node->right);  // ����ҽڵ㣨�սڵ㲻��ջ��

				st.push(node);                          // ����нڵ�
				st.push(NULL); // �нڵ���ʹ������ǻ�û�д�������սڵ���Ϊ��ǡ�

				if (node->left) st.push(node->left);    // �����ڵ㣨�սڵ㲻��ջ��
			}
			else {// ֻ�������սڵ��ʱ�򣬲Ž���һ���ڵ�Ž������
				st.pop();           // ���սڵ㵯��
				node = st.top();    // ����ȡ��ջ��Ԫ��
				st.pop();
				res.push_back(node->val); // ���뵽�����
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
				st.pop(); // ���ýڵ㵯���������ظ������������ٽ�������ڵ���ӵ�ջ��
				st.push(node);                          // ����нڵ�
				st.push(NULL); // �нڵ���ʹ������ǻ�û�д�������սڵ���Ϊ��ǡ�

				if (node->right) st.push(node->right);  // ����ҽڵ㣨�սڵ㲻��ջ��

				if (node->left) st.push(node->left);    // �����ڵ㣨�սڵ㲻��ջ��
			}
			else {// ֻ�������սڵ��ʱ�򣬲Ž���һ���ڵ�Ž������
				st.pop();           // ���սڵ㵯��
				node = st.top();    // ����ȡ��ջ��Ԫ��
				st.pop();
				res.push_back(node->val); // ���뵽�����
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