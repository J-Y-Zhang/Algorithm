#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� => O(n)
 * �ռ临�Ӷ� => O(n)
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int n = nums.size();

        // dp[i]��ʾ��i��β�������������
        vector<int> dp(n + 1);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};