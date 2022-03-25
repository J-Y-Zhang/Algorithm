#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(logn), ֻ�����Ķ����Ƴ����й� 
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        while (n != 0) {
            // ����n�Ķ����Ʊ�ʾ�е����һ��1
            n &= (n - 1);
            ans++;
        }

        return ans;
    }
};