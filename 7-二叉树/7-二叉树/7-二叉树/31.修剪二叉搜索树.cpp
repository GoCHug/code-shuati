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
    //TreeNode* trimBST(TreeNode* root, int low, int high) {
    //    if (root == NULL) return NULL;

    //    if (root->val < low) {
    //        return trimBST(root->right, low, high);//��ǰ�ڵ�û�������� ���������������п����з��ϵ� ���������ݹ��޼�
    //    }
    //    if (high < root->val) {
    //        return trimBST(root->left, low, high);
    //    }

    //    root->left = trimBST(root->left, low, high);
    //    root->right = trimBST(root->right, low, high);

    //    return root;
    //}

    //������
    /*
    �ڼ�֦��ʱ�򣬿��Է�Ϊ������
    ��root�ƶ���[L, R] ��Χ�ڣ�ע��������ұ�����
    ��֦������
    ��֦������
    */
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;

        // ����ͷ��㣬��root�ƶ���[L, R] ��Χ�ڣ�ע��������ұ�
        while (root != nullptr && (root->val < L || root->val > R)) {
            if (root->val < L) root = root->right; // С��L������
            else root = root->left; // ����R������
        }
        TreeNode* cur = root;
        // ��ʱroot�Ѿ���[L, R] ��Χ�ڣ���������Ԫ��С��L�����
        while (cur != nullptr) {
            while (cur->left && cur->left->val < L) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;

        // ��ʱroot�Ѿ���[L, R] ��Χ�ڣ������Һ��Ӵ���R�����
        while (cur != nullptr) {
            while (cur->right && cur->right->val > R) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
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

    int low = 2;
    int high = 6;
    Solution so;
    TreeNode* node = so.trimBST(root, low, high);
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
