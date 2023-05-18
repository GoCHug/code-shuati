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
    //�ݹ鷨
    /*
    ��һ������������СΪ��Ļ���˵���ǿսڵ��ˡ�
    �ڶ����������Ϊ�գ���ôȡ�����������һ��Ԫ����Ϊ�ڵ�Ԫ�ء�
    ���������ҵ������������һ��Ԫ�������������λ�ã���Ϊ�и��
    ���Ĳ����и��������飬�г���������������������� ��˳���㷴�ˣ�һ���������������飩
    ���岽���и�������飬�гɺ���������ͺ���������
    ���������ݹ鴦���������������
    */
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // ��������������һ��Ԫ�أ����ǵ�ǰ���м�ڵ�
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // Ҷ�ӽڵ�
        if (postorder.size() == 1) return root;

        // �ҵ�����������и��
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // �и���������
        // ����ҿ����䣺[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        // postorder ����ĩβԪ��
        postorder.resize(postorder.size() - 1);

        // �и��������
        // ��Ȼ����ҿ���ע������ʹ���������������С��Ϊ�и��
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
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
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    vector<int> postorder = { 9, 15, 7, 20, 3 };
    Solution so;
    TreeNode* root = so.buildTree(inorder, postorder);
    
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
