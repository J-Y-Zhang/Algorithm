#include"LeetCode.h"

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if (n == 0) {
            return true;
        }
        
        return dfs(postorder, 0, n - 1);
    }

    bool dfs(vector<int> &arr, int st, int ed) {
        // �����򵥽ڵ������Ȼ�Ƕ���������
        if (st >= ed) {
            return true;
        }

        // ��¼���ڵ��ֵ, �Դ�Ϊ���ݻ�����������
        int root = arr[ed];

        // Ѱ��������������, ��l��¼
        int t = st;
        while (arr[t] < root) {
            t++;
        }
        int l = t - 1;

        // Ѱ��������������, ��r��¼
        while (arr[t] > root) {
            t++;
        }
        int r = t - 1;

        // ����������Ķ����������ĺ������еĻ�, rootһ���ǵ���r + 1��
        // �������, ˵�����Ƕ���������, ����false
        if (ed != r + 1) {
            return false;
        }
        
        // �ж����������������ǲ��Ƕ���������
        return dfs(arr, st, l) && dfs(arr, l + 1, r);
    }
};