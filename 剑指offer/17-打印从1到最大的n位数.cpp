#include"LeetCode.h"

/**
 * ��ʵû�����������Ǹ���
 */
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;

        // ������ô����, ��ô����???
        int maxNum = pow(10, n);
        for (int i = 1; i < maxNum; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};