#include"LeetCode.h"

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        return mergeSort(nums, 0, n - 1);
    }

    // ��[l, r]��������, ���������������
    int mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) >> 1;

        // �ȼ����������������ڵ����������
        int ans = 0;
        ans += mergeSort(nums, l, mid);
        ans += mergeSort(nums, mid + 1, r);

        vector<int> temp;

        // ��ÿһ��j, ����һ��������β�����������
        // Ҳ�����������б�nums[j]�����������
        // ��nums[i] > nums[j]��ʱ��, ǡ�ø�������mid - i + 1
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                ans += mid - i + 1;
                temp.push_back(nums[j++]);
            }
        }
        
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        while (j <= r) {
            temp.push_back(nums[j++]);
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[l + i] = temp[i];
        }

        return ans;
    }
};