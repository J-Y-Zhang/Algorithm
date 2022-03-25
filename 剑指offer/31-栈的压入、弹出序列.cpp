#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� => O(n)
 * �ռ临�Ӷ� => O(n)
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // ģ��ѹջ, ֻҪջ��Ԫ�غ�ɾ��������,��Ӧ�͵�ջ
        stack<int> stk;
        int n = pushed.size();
        int i = 0;
        for (const auto& val : pushed) {
            stk.push(val);
            while (!stk.empty() && stk.top() == popped[i]) {
                i++;
                stk.pop();
            }
        }

        // ���ģ�������ջ�պõ���, ˵�������������
        return stk.empty();
    }
};