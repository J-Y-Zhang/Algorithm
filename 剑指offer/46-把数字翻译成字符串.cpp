#include"LeetCode.h"

// ��ӵĶ�άdp
// ʱ�ն���O(n)
class Solution {
public:
    int translateNum(int num) {
 
        string str = " " + to_string(num);
        int n = str.size() - 1;

        // dp[k]��ʾ��k��β���ַ������ı�ʾ����
        vector<int> dp(n + 1, 0);

        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            string temp = str.substr(i - 1, 2);
            if (temp >= "10" && temp <= "25") {
                dp[i] = dp[i - 2];
            }
            dp[i] += dp[i - 1];
        }

        return dp[n];
    }
};

// ���������Ż���ռ併��O(1)
class Solution {
public:
    int translateNum(int num) {
        
        string str = " " + to_string(num);
        int n = str.size() - 1;

        // ans��СҲֻ�ܱ�ʾdp[2]
        // dp[1]ֻ�����е�
        if (n == 1) {
            return 1;
        }

        // p -> dp[n - 2]
        // q -> dp[n - 1]
        // ans -> dp[n]
        int p = 1, q = 1, ans = 0; 

        for (int i = 2; i <= n; i++) {
            // ans�����dp[n]��ѭ����ʼ��0
            ans = 0;
            string temp = str.substr(i - 1, 2);
            if (temp >= "10" && temp <= "25") {
                ans = p;
            }
            ans += q;

            // p, q ������
            p = q, q = ans;
        }

        // return dp[n]
        return ans;
    }
};