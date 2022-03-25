#include"LeetCode.h"

class Solution {
public:
    int search(vector<int>& nums, int tar) {
        // �п�
        if (nums.size() == 0) {
            return 0;
        }

        int n = nums.size();

        // ��������Ѱ�ҵ�һ�����ڵ���tar����
        int l = 0, r = n - 1, mid;
        while (l < r) {
            if (nums[mid = (l + r) >> 1] >= tar) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // ����������û�и�Ԫ�ص����
        if (nums[l] != tar) {
            return 0;
        }

        // ��¼������
        int ansL = l;

        // ��������Ѱ�ҵ�һ��С�ڵ���tar����
        l = 0, r = n - 1;
        while (l < r) {
            if (nums[mid = (l + r + 1) >> 1] <= tar) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        // ��¼�Ҷ˵�
        int ansR = l;
        return ansR - ansL + 1;
    }
};