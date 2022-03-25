#include"LeetCode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA), lenB = getLen(headB);

        // ��lenA >= lenB
        if (lenA < lenB) {
            return getIntersectionNode(headB, headA);
        } 

        // A��������lenA - lenB��
        for (int i = lenA - lenB; i != 0; i--) {
            headA = headA->next;
        }

        // ��ͬ������, ֱ���ҵ���ͬ�Ľ��
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

    int getLen(ListNode *head) {
        int ans = 0;
        while (head != NULL) {
            head = head->next;
            ans++;
        }

        return ans;
    }
};