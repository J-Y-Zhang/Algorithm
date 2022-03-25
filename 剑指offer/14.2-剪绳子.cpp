#include"LeetCode.h"


/**
 * ʱ�临�Ӷ� -> O(logn), ������
 * �ռ临�Ӷ� -> O(1)
 */
typedef long long LL;
const int mod = 1e+9 + 7;

class Solution {
public:
    int cuttingRope(int n) {
        // ���n % 3 != 1, ��־����ܶ��3
        int cnt3 = n / 3;

        // ���n % 3 == 1, ������һ��3��1����һ����4, ��Ϊ3 * 1 < 4
        if (n % 3 == 1) {
            cnt3--;
        }

        int ans = quick_mi(3, cnt3, mod);
        int t = n - cnt3 * 3;
        // t���ܵ�ȡֵ��0, 2, 4
        if (t != 0) {
            ans = (LL)ans * t % mod;
        }
        return ans;
    }

    // logn��ʱ�临�Ӷ����(m ^ n) % mod 
    int quick_mi(int m, int n, int mod) {
        int ans = 1, t = m;
        while (n) {
            if (n & 1 == 1) {
                ans = (LL)ans * t % mod;
            }
            t = (LL)t * t % mod;
            n >>= 1;
        }

        return ans;
    }
};