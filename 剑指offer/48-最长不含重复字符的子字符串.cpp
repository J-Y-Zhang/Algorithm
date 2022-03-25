#include"LeetCode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> hash;
        int n = s.size();
        int ans = 0;

        for (int slow = 0, fast = 0; fast < n; fast++) {
            // ����Ҫ��fast��β, ��ôhash(fast)������false�ſ���
            while (hash[s[fast]] == true) {
                hash[s[slow]] = false;
                slow++;
            }

            // ���ڿ�����fast��β��
            hash[s[fast]] = true;
            
            // ���´�
            ans = max(ans, fast - slow + 1);
        }

        return ans;
    }
};