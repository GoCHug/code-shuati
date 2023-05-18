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
private:
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true; // ����Ҷ�ӽڵ㣬���Ҽ���Ϊ0
        if (!cur->left && !cur->right) return false; // ����Ҷ�ӽڵ�ֱ�ӷ���

        if (cur->left) { // ��
            count -= cur->left->val; // �ݹ飬����ڵ�;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // ���ݣ�����������
        }
        if (cur->right) { // ��
            count -= cur->right->val; // �ݹ飬����ڵ�;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; // ���ݣ�����������
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return traversal(root, sum - root->val);
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
    int sum = 7;
	bool res = so.hasPathSum(root, sum);

	cout << res;

	return 0;
}
