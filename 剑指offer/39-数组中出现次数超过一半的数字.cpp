#include"LeetCode.h"

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // ���a�ĳ��ִ����������ȵ�һ��, �������, �м����һ����a
        return nums[nums.size() >> 1];
    }
};