#include"LeetCode.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);

        // ���˵��һ��������1
        dp[1] = 1;

        // ά������ָ��, ������ǰ����
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            // ��Ӧ��ָ�����Ӧ������
            // ����, ���� * (2 | 3 | 5)�����ǳ���, ������������ȷ��
            int t2 = dp[p2] * 2, t3 = dp[p3] * 3, t5 = dp[p5] * 5;
            dp[i] = min(t2, min(t3, t5));

            // ����һ��������else if!!!
            // ������Ϊ���������ظ�, ��t2��t3��t5�����ظ�
            // ����2 * 3��3 * 2
            // ���һ��Ҫ��if�ֱ��ж�
            if (dp[i] == t2) {
                p2++;
            }
            if (dp[i] == t3) {
                p3++;
            }
            if (dp[i] == t5) {
                p5++;
            }
        }

        return dp[n];
    }
};