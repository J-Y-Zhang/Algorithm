#include"LeetCode.h"

class CQueue {
public:
    // ����ջ
    stack<int> stk1, stk2;
    
    // push��ֱ����stk1��push����
    void appendTail(int value) {
        stk1.push(value);
    }
    
    // popҪ���������, ����˼·�ǽ�stk1ͨ��stk2�����׳���
    int deleteHead() {
        if (stk2.size() != 0) { // ���stk2��û�����, ��ֱ�ӳ���
            int ans = stk2.top();
            stk2.pop();
            return ans;
        } else if (stk1.size() != 0) { // �������stk1����Ԫ��, �ͷ����׳���, Ȼ�����
            while (!stk1.empty()) {
                int t = stk1.top();
                stk1.pop();
                stk2.push(t);
            }
            // Ͷ��ȡ����Ϊ
            return deleteHead();
        }

        // �ն���, ������ĿҪ�󷵻�-1
        return -1;
    }
};