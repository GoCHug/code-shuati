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

//�ݹ鷨
class Solution {
private:
    int maxCount = 0; // ���Ƶ��
    int count = 0; // ͳ��Ƶ��
    TreeNode* pre = NULL;
    vector<int> result;
    void searchBST(TreeNode* cur) {
        if (cur == NULL) return;

        searchBST(cur->left);       // ��
        // ��
        if (pre == NULL) { // ��һ���ڵ�
            count = 1;
        }
        else if (pre->val == cur->val) { // ��ǰһ���ڵ���ֵ��ͬ
            count++;
        }
        else { // ��ǰһ���ڵ���ֵ��ͬ
            count = 1;
        }
        pre = cur; // ������һ���ڵ�

        if (count == maxCount) { // ��������ֵ��ͬ���Ž�result��
            result.push_back(cur->val);
        }

        if (count > maxCount) { // ��������������ֵƵ��
            maxCount = count;   // �������Ƶ��
            result.clear();     // �ܹؼ���һ������Ҫ�������result��֮ǰresult���Ԫ�ض�ʧЧ��
            result.push_back(cur->val);
        }

        searchBST(cur->right);      // ��
        return;
    }

public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = NULL; // ��¼ǰһ���ڵ�
        result.clear();

        searchBST(root);
        return result;
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);


    int val = 2;

    Solution so;
    vector<int> res = so.findMode(root);
    for (int& x : res) {
        cout << x << " ";
    }

    return 0;
}
