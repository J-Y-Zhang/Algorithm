#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n * n), ˫��ѭ��
 * �ռ临�Ӷ� -> O(n)
 */
class Solution {
public:
    int cuttingRope(int n) {
        // ���Ҫ��������������, ��ʵ����2��3����Ȳ����
        // Ҳ����˵, 2��3��dp�ı߽�����
        // ���Զ��ڳ���С�ڵ���3������, ����Ҫdp, Ҳ����Ҫ����
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }

        vector<int> dp(n + 1, 0);
        // ���Ҫ��������������, ��ʵ����2��3����Ȳ����, ��Ϊ�߽�
        dp[1] = 1, dp[2] = 2, dp[3] = 3;

        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= (i >> 1); j++) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }

        return dp[n];
    }
};