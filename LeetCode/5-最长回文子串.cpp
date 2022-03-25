#include"LeetCode.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        // dp[i][j]��ʾ[i, j]���Ӵ��ǲ��ǻ��Ĵ�
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        // ����Ϊ1, ��Ȼ�ǻ��Ĵ�
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        

        // ��¼��
        int start = 0, length = 1;

        // ö�ٳ���dp, ��2��ʼö�ټ���
        for (int len = 2; len <= n; len++) {
            for (int st = 0; st + len - 1 < n; st++) {
                int ed = st + len - 1;

                // ����һ�³���Ϊ2�����
                if (len == 2) {
                    dp[st][ed] = (s[st] == s[ed]);
                } else {
                    dp[st][ed] = (s[st] == s[ed] && dp[st + 1][ed - 1]); 
                }

                if (dp[st][ed] == true && len > length) {
                    start = st;
                    length = len;
                }
            }
        }

        return s.substr(start, length);
    }
};