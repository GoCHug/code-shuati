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
	////��ͨ�������ⷨ
	//int getNum(TreeNode* node) {
	//	if (node == NULL) return 0;

	//	int leftNum = getNum(node->left);
	//	int rightNum = getNum(node->right);
	//	int treeNum = 1 + leftNum + rightNum;
	//	return treeNum;
	//}
	//int countNodes(TreeNode* root) {
	//	return getNum(root);
	//}
	////��ͨ������������ ����
	//int countNodes(TreeNode* root) {
	//	queue<TreeNode*> que;
	//	if (root != NULL) que.push(root);
	//	int result = 0;
	//	while (!que.empty()) {
	//		int size = que.size();
	//		for (int i = 0; i < size; i++) {
	//			TreeNode* node = que.front();
	//			que.pop();
	//			result++;   // ��¼�ڵ�����
	//			if (node->left) que.push(node->left);
	//			if (node->right) que.push(node->right);
	//		}
	//	}
	//	return result;
	//}

	//��ȫ�������ⷨ
	int getNum(TreeNode* node) {
		if (node == NULL) return 0;
		// ��ֹ���� ��������
		// ��ʼ��������Ⱥ�������Ƿ���ͬ���жϸ������ǲ�����������
		TreeNode* left = node->left;
		TreeNode* right = node->right;
		int leftNum = 0, rightNum = 0;// �����ʼΪ0����Ŀ�ĵģ�Ϊ��������ָ������
		while (left) {
			leftNum++;
			left = left->left;
		}
		while (right) {
			rightNum++;
			right = right->right;
		}
		if (leftNum == rightNum) {
			return (2 << leftNum) - 1;// ע��(2<<1) �൱��2^2�������������������������ڵ�����
		}

		//����ݹ��߼�
		int leftTreeNum = getNum(node->left);			//��
		int rightTreeNum = getNum(node->right);			//��
		int resNum = 1 + leftTreeNum + rightTreeNum;	//��
		return resNum;
	}
	int countNodes(TreeNode* root) {
		return getNum(root);
	}
};


int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	Solution so;
	int res = so.countNodes(root);

	cout << res;
	return 0;
}