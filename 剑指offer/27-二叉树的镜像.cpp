#include"LeetCode.h"

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    // �ݹ��ȥ����������������
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        swap(root->left, root->right);

        dfs(root->left);
        dfs(root->right);
    }
};