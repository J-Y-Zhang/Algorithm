#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n)
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        // ���п�����
        if (head == NULL) {
            return {};
        }

        // ans
        vector<int> ans;

        // ��ת����(˫ָ��)
        // p -> head��ǰһ�����
        ListNode* p = NULL;
        while (head != NULL) {
            // ����head->next
            ListNode* ne = head->next;

            // �ı�head->nextָ��Ϊ��ǰָ
            head->next = p;

            // ����p��head
            p = head;
            head = ne;
        }

        // ��ת��head = NULL, p�����������ͷ���, ��¼�𰸼���
        while (p != NULL) {
            ans.push_back(p->val);
            p = p->next;
        }

        return ans;
    }
};