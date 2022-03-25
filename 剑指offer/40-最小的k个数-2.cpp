#include"LeetCode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() == 0 || k == 0) {
            return {};
        }

        quick_select(arr, 0, arr.size() - 1, k);

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }

    // ��l��r�����ڵ�ǰkС�����Ƶ�[l, l + k)������
    void quick_select(vector<int>& arr, int l, int r, int k) {
        if (l == r) {
            return;
        }

        // ������С�ڵ����ڱ���������ǰ��
        // ���д��ڵ����ڱ��������ں���

        int i = l - 1, j = r + 1;
        int flag = arr[(l + r) >> 1];
        while (i < j) {
            while (arr[++i] < flag);
            while (arr[--j] > flag);
            // һ��Ҫ����, ��ֹ����Ľ���
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        // [l, j]����С�ڵ����ڱ�������, ����lenL = j - l + 1
        int lenL = j - l + 1;
        if (lenL == k) {
            return;
        } else if (lenL < k) {
            // ����k����, ��Ҫ�������䲹k - lenL����
            quick_select(arr, j + 1, r, k - lenL);
        } else if (lenL > k) {
            // ����k����, ���һ��ɸѡ
            quick_select(arr, l, j, k);
        }
    }
};