#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n), n�εݹ齨��n�����
 * �ռ临�Ӷ� -> O(n), ��ϣ��O(n) + �ݹ�O(n), �ݹ���O(n)����Ϊÿһ�εݹ�Ὠ��һ�����
 */
class Solution {
public:
    // ��ϣ������Ԥ������������
    unordered_map<int, int> hash;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // ���п���
        if (preorder.size() == 0) {
            return NULL;
        }

        // �ù�ϣ��Ԥ������������
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }

        // dfs
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* dfs(vector<int>& pre, vector<int>& in, int preL, int preR, int inL, int inR) {
        // �߽�
        if (preL > preR) {
            return NULL;
        }

        // �����
        TreeNode* root = new TreeNode(pre[preL]);

        // �ӹ�ϣ��ȡ�����������и���λ��
        int rootPos = hash[root->val];

        // ͨ�����������и���λ�������������������
        int lenL = rootPos - inL, lenR = inR - rootPos; 

        // �ݹ鹹����������
        root->left = dfs(pre, in, preL + 1, preL + lenL, inL, rootPos - 1);
        root->right = dfs(pre, in, preL + lenL + 1, preR, rootPos + 1, inR);
        
        return root;
    }
};