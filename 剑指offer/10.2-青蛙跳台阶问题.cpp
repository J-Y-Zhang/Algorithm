#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n), dp
 * �ռ临�Ӷ� -> O(1), ���������Ż�, ��ά��һά
 */
const int mod = 1e+9 + 7;

class Solution {
public:
    int numWays(int n) {
        // nС��2ʱ����Ҫ����, ���е�
        if (n < 2) {
            return 1;
        }

        // dp + ��������, ѭ��n - 1�η���b(������n = 2Ϊ��, ѭ��1�η���b����)
        int a = 1, b = 1;
        while (n > 1) {
            int t = b;
            b = (a + b) % mod;
            a = t;

            n--;
        }

        return b;
    }
};