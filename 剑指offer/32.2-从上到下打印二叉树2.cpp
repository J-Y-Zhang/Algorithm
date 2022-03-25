#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� => O(n), ÿ�����ֻ�ᱻ����һ��
 * �ռ临�Ӷ� => O(n), Ҫά��һ����������bfs 
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // ���п�
        if (root == NULL) {
            return {};
        }

        vector<vector<int>> ans;

        // bfs�õĶ���
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> v;

            // Ϊ��ȡһ�������, Ҳ����ȡq.size()������, Ҫʹ��ѭ��
            // ����Ϊq.size()�Ƕ�̬�仯��, ����Ҫ��ȡ��ʼ��q.size(), Ȼ����ѭ��
            for (int i = q.size(); i != 0; i--) {
                auto t = q.front();
                q.pop();
                
                v.push_back(t->val);
                // �������Ͳ��÷Ž�������, �Ǳ߽�
                if (t->left != NULL) {
                    q.push(t->left);
                }
                if (t->right != NULL) {
                    q.push(t->right);
                }
            }

            ans.push_back(v);
        }

        return ans;
    }
};