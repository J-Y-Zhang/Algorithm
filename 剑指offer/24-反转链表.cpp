#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n), ˫ָ��
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ˫ָ��
        ListNode* p = NULL;

        while (head != NULL) {
            // ����һ��head�ĺ�һ�����
            ListNode* ne = head->next;

            // ��ת����
            head->next = p;
            
            // ˫ָ��ͬ������
            p = head, head = ne;
        }

        return p;
    }
};