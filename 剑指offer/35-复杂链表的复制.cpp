#include"LeetCode.h"

class Solution {
public:
    // ��ֹ�ظ�����, Ҫ���ÿһ���ɽ���Ƿ񱻸��ƹ�
    unordered_map<Node*, Node*> hash;

    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        return dfs(head);
    }

    // ����һ����headΪͷ�ĸ�������, �������������ͷָ��
    Node* dfs(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        // �����ظ�����
        if (hash[head] != NULL) {
            return hash[head];
        }

        // ����ͷ���
        auto newHead = new Node(head->val);

        // һ��Ҫ����������ϣ��
        // �Է�ֹ��������dfs�ٴ��ѵ�head, ����ظ����ƣ� Ȼ�����޵ݹ���ջ���
        hash[head] = newHead;

        // �ݹ鸴��head��next��random, ����newHead������
        newHead->next = dfs(head->next);
        newHead->random = dfs(head->random);

        return newHead;
    }
};













































// ���ù�, �ٷ��ṩ�����ݽṹ
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};