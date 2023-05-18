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
	//�ݹ鷨 ����
	int getHeight(TreeNode* node) {
		//��ֹ����
		if (node == NULL) return 0;

		//����ݹ��߼�
		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);
		if (node->left == NULL && node->right != NULL) return 1 + rightHeight;
		else if (node->left != NULL && node->right == NULL) return 1 + leftHeight;
		return 1 + min(leftHeight, rightHeight);//���Ҷ�Ϊ�շ��ؾ���1+0
	}
	int minDepth(TreeNode* root) {
		return getHeight(root);
	}


	//������ ���� �����Һ��Ӷ�Ϊ�յ�ʱ�򣬲�˵����������͵���
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++; // ��¼��С���
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
				if (!node->left && !node->right) { // �����Һ��Ӷ�Ϊ�յ�ʱ��˵������͵��һ���ˣ��˳�
					return depth;
				}
			}
		}
		return depth;
	}
};


int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(4);

	Solution so;
	int res = so.minDepth(root);

	cout << res;
	return 0;
}