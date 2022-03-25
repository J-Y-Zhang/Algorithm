#include"LeetCode.h"

class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) {
            return 0;
        }

        int ans = 0;

        // ����������Ϊ��������, high, cur��low
        int low = 0, high = n / 10, cur = n % 10;

        // long long��ֹ���
        long long digit = 1;

        // ������curΪ0��highΪ0������ֹͣ����
        while (cur != 0 || high != 0) {
            // �������, high(0 �� high - 1) * digit��1�ǿ϶��е�
            ans += high * digit;

            // ����cur��ֵ�жϵ���λ����highʱ�����
            if (cur == 1) {
                ans += low + 1;
            } else if (cur > 1) {
                ans += digit;
            }
            
            // ����
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }

        return ans;
    }
};