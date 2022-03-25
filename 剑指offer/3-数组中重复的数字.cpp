#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n), ��Ϊÿһ�ν��������λһ������, n�ν���֮�ڱ�Ȼ�õ����
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // ÿ�����ֶ�Ӧ����Ψһ��, ����ÿһ�ν������Ὣһ�����ֹ�λ
            while (nums[i] != i) {
                // ���nums[nums[i]]�Ѿ���ȷ��λ��,���Ǿͻ�õ������nums[i], return����
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }

                // ��nums[i]�͵���ȷ��λ��
                swap(nums[i], nums[nums[i]]);
            }
        }

        // ��һ������, ���return����
        return 0;
    }
};