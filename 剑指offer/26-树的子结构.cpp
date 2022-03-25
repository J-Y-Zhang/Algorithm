#include"LeetCode.h"

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // �������Լ��, �����������������ӽṹ
        // �����ݳ�ʶ, ����ǿ���Ҳ���ǿ������ӽṹ
        if (A == NULL || B == NULL) {
            return false;
        }

        // ����ҲҪ�ݹ��ԭ����
        // A�������ĸ��ڵ��B�ĸ��ڵ����Ҳ�ǿ��Ե�
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    // �ж�b�Ƿ���a���ӽṹ(a��b�ĸ��ڵ����)
    bool dfs(TreeNode* a, TreeNode* b) {
        // ע���ʱbΪ����Ҫreturn true��
        // ��Ϊ�����Ѿ���ȷ��B���ǿ���
        // bΪ�շ������������뿴�������, ������dfs�ı߽�
        if (b == NULL) {
            return true;
        }

        // a��b���� �� a,b��ֵ����� 
        // ����false
        if (a == NULL || a->val != b->val) {
            return false;
        }

        return dfs(a->left, b->left) && dfs(a->right, b->right);
    }
};