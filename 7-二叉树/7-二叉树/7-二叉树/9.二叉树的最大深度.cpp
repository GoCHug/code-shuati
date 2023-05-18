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

//���ڵ�ĸ߶Ⱦ��Ƕ�������������
class Solution {
public:
	////�ݹ鷨 ����
	//int getHeight(TreeNode* node) {
	//	//��ֹ����
	//	if (node == NULL) return 0;

	//	//����ݹ��߼�
	//	int leftHeight = getHeight(node->left);
	//	int rightHeight = getHeight(node->right);
	//	int height = 1 + max(leftHeight, rightHeight);
	//	return height;
	//}
	//int maxDepth(TreeNode* root) {
	//	return getHeight(root);
	//}

	//������ ���� ������Ⱦ��Ƕ������Ĳ������Ͳ�������ķ�ʽ�����Ǻ�
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return depth;
	}

};


int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(4);

	Solution so;
	int res = so.maxDepth(root);

	cout << res;
	return 0;
}