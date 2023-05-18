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
		path.push_back(cur->val); // 中，中为什么写在这里，因为最后一个叶子节点也要加入到path中
		//终止条件 到了叶子节点
		if (cur->left == NULL && cur->right == NULL) { // 遇到叶子节点
			string sPath;
			for (int i = 0; i < path.size() - 1; i++) { // 将path里记录的路径转为string格式
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]); // 记录最后一个节点（叶子节点）
			result.push_back(sPath); // 收集一个路径
			return;
		}

		if (cur->left) { // 左 
			traversal(cur->left, path, result);
			path.pop_back(); // 回溯
		}
		if (cur->right) { // 右
			traversal(cur->right, path, result);
			path.pop_back(); // 回溯
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