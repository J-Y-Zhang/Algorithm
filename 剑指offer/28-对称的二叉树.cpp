#include"LeetCode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // �����ǶԳƵ�
        if (root == NULL) {
            return true;
        }

        return dfs(root->left, root->right);
    }

    // rootҪ��Գ�, root��������������ԳƵ�
    // �˺��������ж����������Ƿ�Գ�
    bool dfs(TreeNode* A, TreeNode* B) {
        if (A == NULL && B == NULL) {
            return true;
        }

        if (A == NULL || B == NULL || A->val != B->val) {
            return false;
        }

        // A��BҪ��Գ�, A�������������B���������Գ�
        // A�������������B���������Գ�(���Թ۲�����)
        return dfs(A->left, B->right) && dfs(A->right, B->left);
    }
};