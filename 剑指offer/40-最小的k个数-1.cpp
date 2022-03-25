#include"LeetCode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0 || arr.size() == 0) {
            return {};
        }

        // priority_queueĬ���Ǵ����
        priority_queue<int> heap;

        int n = arr.size();

        // ��ʼ����, ��ǰk��Ԫ�ط����
        for (int i = 0; i < k; i++) {
            heap.push(arr[i]);
        }

        for (int i = k; i < n; i++) {
            // ���arr[i]���ڶ��е����ֵ, ����һ��������С��k����
            // ��֮, ���е����ֵһ��������С��k����
            if (arr[i] < heap.top()) {
                heap.pop();
                heap.push(arr[i]);
            }
        }

        vector<int> ans;
        while (heap.empty() == false) {
            ans.push_back(heap.top());
            heap.pop();
        }

        return ans;
    }
};