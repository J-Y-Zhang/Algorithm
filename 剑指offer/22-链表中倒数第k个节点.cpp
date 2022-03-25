#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n), ˫ָ��
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // ˫ָ��, p����k��, Ȼ��ͬ���ƶ�p��head, pΪNULLʱhead���ǵ�����k�������
        ListNode* p = head;

        // Ϊʲôwhile(k--)����ȷ��? ����������ģ��һ��
        while (k--) {
            p = p->next;
        }

        // ͬ�����Ƽ���
        while (p != NULL) {
            head = head->next;
            p = p->next;
        }

        return head;
    }
};