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
	void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
		path.push_back(cur->val); // �У���Ϊʲôд�������Ϊ���һ��Ҷ�ӽڵ�ҲҪ���뵽path��
		//��ֹ���� ����Ҷ�ӽڵ�
		if (cur->left == NULL && cur->right == NULL) { // ����Ҷ�ӽڵ�
			string sPath;
			for (int i = 0; i < path.size() - 1; i++) { // ��path���¼��·��תΪstring��ʽ
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]); // ��¼���һ���ڵ㣨Ҷ�ӽڵ㣩
			result.push_back(sPath); // �ռ�һ��·��
			return;
		}

		if (cur->left) { // �� 
			traversal(cur->left, path, result);
			path.pop_back(); // ����
		}
		if (cur->right) { // ��
			traversal(cur->right, path, result);
			path.pop_back(); // ����
		}
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		vector<int> path;
		if (root == NULL) return result;
		traversal(root, path, result);
		return result;
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

	Solution so;
	vector<string> res = so.binaryTreePaths(root);

	for (auto& s : res) {
		cout << s << endl;
	}

	return 0;
}