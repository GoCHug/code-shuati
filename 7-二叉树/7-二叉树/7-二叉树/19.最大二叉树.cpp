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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        int numMax = INT_MIN;
        int indexMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > numMax) {
                numMax = nums[i];
                indexMax = i;
            }
        }
        TreeNode* root = new TreeNode(numMax);
        
        vector<int> leftNums(nums.begin(), nums.begin() + indexMax);
        vector<int> rightNums(nums.begin() + indexMax + 1, nums.end());
        root->left = constructMaximumBinaryTree(leftNums);//��Ϊǰ���ж��˿յ���������ﲻ�����жϿ��� if (nums.size() == 0) return NULL;
        root->right = constructMaximumBinaryTree(rightNums);
        //һ�������˵������ÿսڵ㣨��ָ�룩����ݹ飬�Ͳ���if��
        //������ÿսڵ����ݹ飬�ͼ�if����һ�£� ��ֹ����Ҳ����Ӧ�ĵ�����
        return root;
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
    vector<int> nums = { 3,2,1,6,0,5 };
    Solution so;
    TreeNode* root = so.constructMaximumBinaryTree(nums);

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
