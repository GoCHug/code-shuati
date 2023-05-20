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

//�����Ǹı����Ľṹ�Ĳ��뷽ʽ
class Solution {
public:
    ////�ݹ鷨
    //TreeNode* insertIntoBST(TreeNode* root, int val) {
    //    if (root == NULL) {
    //        TreeNode* node = new TreeNode(val);
    //        return node;
    //    }

    //    if (val < root->val) {
    //        root->left = insertIntoBST(root->left, val);
    //    }
    //    if (root->val < val) {
    //        root->right = insertIntoBST(root->right, val);
    //    }
    //    return root;
    //}

    //������
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* cur = root;
        TreeNode* parent = root; // �������Ҫ����Ҫ��¼��һ���ڵ㣬�����޷���ֵ�½ڵ�
        while (cur != NULL) {
            parent = cur;
            if (cur->val > val) cur = cur->left;
            else cur = cur->right;
        }
        TreeNode* node = new TreeNode(val);
        if (val < parent->val) parent->left = node;// ��ʱ����parent�ڵ�Ľ��и�ֵ
        else parent->right = node;
        return root;
    }

    //������� ��ӡ�����
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
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 6;
    Solution so;
    TreeNode* node = so.insertIntoBST(root, val);
    //���������ӡ���
    vector<vector<int>> res = so.levelOrder(node);
    for (auto& x : res) {
        for (int& t : x) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
