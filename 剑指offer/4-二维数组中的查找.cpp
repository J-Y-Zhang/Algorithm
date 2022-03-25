#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n), ���ָ��Ҳ���ƶ�row + col��
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // ������Ŀ��Χ, ��Ҫ����
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        // row -> ��, col -> ��
        int row = matrix.size(), col = matrix[0].size();

        // �����Ͻ�(�������½�)��ʼ��, �������ܸ��ݵ�ǰֵ�Ĵ�СΨһ�ĸ���ָ��
        // �������Ͻ�(�����½�)��ʼ��, ����ж�����
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                return true;
            }
        }

        return false;
    }
};