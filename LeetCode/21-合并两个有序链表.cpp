#include"LeetCode.h"

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto ans = new ListNode(0, NULL), p = ans;
        for(; l1 and l2; p = p->next)
            if(l1->val < l2->val)
                p->next = l1, l1 = l1->next;
            else
                p->next = l2, l2 = l2->next;
        
        p->next = l1 ? l1 : l2;

        return ans->next;
    }
};