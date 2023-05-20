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
    //������
    TreeNode* deleteNode(TreeNode* root, int key) {
        /*
        ��ֹ���� ���������������
        ��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
        �ҵ�ɾ���Ľڵ㣺
        �ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
        �����������ɾ���ڵ������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ�������Һ���Ϊ���ڵ�
        �����������ɾ���ڵ���Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
        ��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ��������ͷ��㣨���ӣ��ŵ�ɾ���ڵ��������
        ��������ڵ�������ϣ�����ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
        */
        if (root == NULL) return NULL;//1
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {//2
                delete root;
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL) {//3
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
            else if (root->left != NULL && root->right == NULL) {//4
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            }
            else {//5
                TreeNode* cur = root->right;
                while (cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
        }

        //�����߼�
        if (key < root->val) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
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

    int key = 2;
    Solution so;
    TreeNode* node = so.deleteNode(root, key);
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
