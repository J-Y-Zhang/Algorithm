#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(logn), ���� 
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    int minArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;

        // ���Ժ��л�ֽ�ϻ���һ��ֱ������ϵ��ͼ��
        while (l < r) {
            // �����ֵС���Ҷ˵�ֵ, ˵��min����ֵ����ֵ�����
            if (nums[mid = (l + r) >> 1] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) { // �����ֵ�����Ҷ˵�ֵ, �����Ҳ�, ����ֵ������Сֵ
                l = mid + 1;
            } else { // �����ֵ���Ҷ˵�ֵ���, �����������, ֻ�ܶ϶��Ҷ˵㲻����Ҫ(���Ա���ֵ����)
                r--;
            }
        }

        return nums[l];
    }
};

/**
 * 1.xxx
 * 2.xxx
 */