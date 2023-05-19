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
    ////�ݹ鷨
    //TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //    if (root1 == NULL) return root2;
    //    if (root2 == NULL) return root1;

    //    root1->val += root2->val;
    //    root1->left = mergeTrees(root1->left, root2->left);
    //    root1->right = mergeTrees(root1->right, root2->right);
    //    return root1;
    //}

    //������
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            // ��ʱ�����ڵ�һ����Ϊ�գ�val���
            node1->val += node2->val;

            // �����������ڵ㶼��Ϊ�գ��������
            if (node1->left != NULL && node2->left != NULL) {
                que.push(node1->left);
                que.push(node2->left);
            }
            // ����������ҽڵ㶼��Ϊ�գ��������
            if (node1->right != NULL && node2->right != NULL) {
                que.push(node1->right);
                que.push(node2->right);
            }

            // ��t1����ڵ� Ϊ�� t2��ڵ㲻Ϊ�գ��͸�ֵ��ȥ
            if (node1->left == NULL && node2->left != NULL) {
                node1->left = node2->left;
            }
            // ��t1���ҽڵ� Ϊ�� t2�ҽڵ㲻Ϊ�գ��͸�ֵ��ȥ
            if (node1->right == NULL && node2->right != NULL) {
                node1->right = node2->right;
            }
            // ��t1�Ĳ��� t2�գ���ʵ����t1ԭ����ֵ ���Բ���д
        }
        return root1;
        
    }


    //������� ��ӡ���
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
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);


    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);


    Solution so;
    TreeNode* root = so.mergeTrees(root1, root2);

    //���������ӡ���
    vector<vector<int>> res = so.levelOrder(root);
    for (auto& x : res) {
        for (int& t : x) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
