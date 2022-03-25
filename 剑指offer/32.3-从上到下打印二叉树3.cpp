#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� => O(n), ÿ�����ֻ�ᱻ����һ��
 * �ռ临�Ӷ� => O(n), Ҫά��һ����������bfs 
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<vector<int>> ans;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // ʹ��˫�˶���������"֮����"������
            deque<int> d;

            // Ϊ��ȡһ�������, Ҳ����ȡq.size()������, Ҫʹ��ѭ��
            // ����Ϊq.size()�Ƕ�̬�仯��, ����Ҫ��ȡ��ʼ��q.size(), Ȼ����ѭ��
            for (int i = q.size(); i != 0; i--) {
                auto t = q.front();
                q.pop();

                // ����flag�жϷ���
                if (flag == true) {
                    d.push_back(t->val);
                } else {
                    d.push_front(t->val);
                }

                if (t->left != NULL) {
                    q.push(t->left);
                }
                if (t->right != NULL) {
                    q.push(t->right);
                }
            }

            vector<int> v;
            while (!d.empty()) {
                v.push_back(d.front());
                d.pop_front();
            }
            ans.push_back(v);
            flag = !flag;
        }

        return ans;
    }
};