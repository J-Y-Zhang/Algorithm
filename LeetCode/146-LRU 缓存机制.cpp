#include"LeetCode.h"

struct MyNode {
    int key, val;
    MyNode* next;
    MyNode* prev;
};

class LRUCache {
public:
    int cap;
    int cnt = 0;
    MyNode* head;
    MyNode* tail;
    unordered_map<int, MyNode*> hash;
    LRUCache(int capacity) {
        this->cap = capacity;
        this->head = new MyNode({0, 0, NULL, NULL});
        this->tail = new MyNode({0, 0, NULL, NULL});
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if (hash.count(key) == 0) {
            return -1;
        }

        // �����Ծ��Ԫ�شӵ�ǰλ��ɾ��
        auto t = hash[key];
        t->prev->next = t->next;
        t->next->prev = t->prev;
        
        // �����Ծ��Ԫ����ӵ���ͷ
        t->next = head->next;
        t->prev = head;
        head->next->prev = t;
        head->next = t;

        return hash[key]->val;
    }
    
    void put(int key, int value) {
        // �������Ѿ���key��, ���¼���
        if (hash.count(key) == 1) {
            // �����Ծ��Ԫ�شӵ�ǰλ��ɾ��
            auto t = hash[key];
            t->prev->next = t->next;
            t->next->prev = t->prev;
            
            // �����Ծ��Ԫ����ӵ���ͷ
            t->next = head->next;
            t->prev = head;
            head->next->prev = t;
            head->next = t;

            // ������ֵ
            hash[key]->val = value;
        } else { // û�д�key, �����

            // ���LRU����, Ҫɾ�����Ծ��Ԫ��
            if (this->cap == this->cnt) {
                // �����Ծ�ı�βԪ�شӹ�ϣ�������ɾ��
                hash.erase(tail->prev->key);
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;
            } else {
                this->cnt++;
            }

            // ����Ԫ����ӵ���ϣ��
            auto t = new MyNode({key, value, NULL, NULL});
            hash[key] = t;

            // ����Ԫ����ӵ���ͷ
            t->next = head->next;
            t->prev = head;
            head->next->prev = t;
            head->next = t;
        }
    }
};

