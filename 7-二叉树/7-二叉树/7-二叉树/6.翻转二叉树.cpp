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
		////�ݹ鷨
		//if (root == NULL) return root;
		////��Ϊ����ǰ������������Ƚ��н������Һ��ӽڵ㣬Ȼ��ת����������ת��������
		////����Ҳ�У������С�ʹ�õݹ�����������ĳЩ�ڵ�����Һ��ӻᷭת���Ρ�
		//swap(root->left, root->right);
		//invertTree(root->left);
		//invertTree(root->right);
		//return root;

		////��������ǰ�������
		//stack<TreeNode*> st;
		//if (root != NULL) st.push(root);
		//while (!st.empty()) {
		//	TreeNode* node = st.top();				//��
		//	st.pop();
		//	swap(node->left, node->right);
		//	if (node->right) st.push(node->right);	//��
		//	if (node->left) st.push(node->left);	//��
		//}
		//return root;

		////����ͳһ����ǰ�������
		//stack<TreeNode*> st;
		//if (root != NULL) st.push(root);
		//while (!st.empty()) {
		//	TreeNode* node = st.top();
		//	if (node != NULL) {
		//		st.pop();
		//		if (node->right) st.push(node->right);  // ��
		//		if (node->left) st.push(node->left);    // ��
		//		st.push(node);                          // ��
		//		st.push(NULL);
		//	}
		//	else {
		//		st.pop();
		//		node = st.top();
		//		st.pop();
		//		swap(node->left, node->right);          // �ڵ㴦���߼�
		//	}
		//}
		//return root;

		//����
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				swap(node->left, node->right); // �ڵ㴦��
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return root;



    }


	//���������ӡ���
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			// ����һ��Ҫʹ�ù̶���Сsize����Ҫʹ��que.size()����Ϊque.size�ǲ��ϱ仯��
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