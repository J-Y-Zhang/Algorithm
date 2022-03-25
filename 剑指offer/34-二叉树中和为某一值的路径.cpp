#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        if (root == NULL) {
            return {};
        }
        
        vector<int> v;
        dfs(v, tar, root);

        return ans;
    }

    void dfs(vector<int> &v, int tar, TreeNode* root) {
        // Ҷ�ӽ����Ϊ�����ı߽�
        if (root->left == NULL && root->right == NULL) {
            // �ж��Ƿ����
            if (tar == root->val) {
                v.push_back(tar);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }

        // ��tar��ȥ���ڵ��ֵ, Ȼ�������������ݹ�����
        tar -= root->val;
        if (root->left != NULL) {
            // �����㷨, һ��Ҫpop_back()
            v.push_back(root->val);
            dfs(v, tar, root->left);
            v.pop_back();
        }

        if (root->right != NULL) {
            v.push_back(root->val);
            dfs(v, tar, root->right);
            v.pop_back();
        }
    }


};