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
	//�ݹ鷨
	//���ʹ�õݹ鷨������ж������һ���أ���ʵ�����������Ҷ�ӽڵ�һ�������һ�С�
	int maxDepth = INT_MIN;   // ȫ�ֱ��� ��¼������
	int result;       // ȫ�ֱ��� ����������ڵ����ֵ
	void traversal(TreeNode* root, int depth) {
		//��ֹ����
		if (root->left == NULL && root->right == NULL) {
			if (depth > maxDepth) {
				maxDepth = depth;
				result = root->val;
			}
			return;
		}
		//�����߼�
		if (root->left) {
			depth++;
			traversal(root->left, depth);
			depth--; // ����
		}
		if (root->right) {
			depth++;
			traversal(root->right, depth);
			depth--; // ����
		}
		return;
	}
	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 1);
		return result;
	}


	////������ ������� ֻ��Ҫ��¼���һ�е�һ���ڵ����ֵ�Ϳ�����
	//int findBottomLeftValue(TreeNode* root) {
	//	queue<TreeNode*> que;
	//	if (root != NULL) que.push(root);
	//	int res = 0;
	//	while (!que.empty()) {
	//		int size = que.size();
	//		for (int i = 0; i < size; i++) {
	//			TreeNode* node = que.front();
	//			que.pop();
	//			if (i == 0) res = node->val;// ��¼���һ�е�һ��Ԫ��
	//			if (node->left) que.push(node->left);
	//			if (node->right) que.push(node->right);
	//		}
	//	}
	//	return res;
	//}
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
	int res = so.findBottomLeftValue(root);

	cout << res;

	return 0;
}
