#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n) 
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        // ���ǵ�ɾ��ͷ�������, ��һ��αͷ�����������һ����
        auto ans = new ListNode(0, head);
        
        auto p = ans;
        while (p->next != NULL) {
            if (p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return ans->next;
    }
};