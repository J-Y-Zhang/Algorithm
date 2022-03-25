#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n), ����˫ָ��
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        
        // [0, slow)ȫ������, ������Ϊÿ��slow++����������������������
        // [slow, fast)����ȫ��ż��, ������Ϊfastָ��ֻ������slow������, ������[0, slow)��
        int fast = 0, slow = 0;

        while (fast < n) {
            // ����������, �Ͱ�����slow�ϵ�ż������, slow����
            if (nums[fast] & 1) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }

        return nums;
    }
};