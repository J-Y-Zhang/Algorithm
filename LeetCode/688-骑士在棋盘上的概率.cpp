#include "LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n^2 * k), ����ѭ��
 * �ռ临�Ӷ� -> O(n^2 * k)
 */
class Solution {
public:
  // ƫ��������, ��˵������߷���ְ�
  int X[8] = {1, 1, 2, 2, -1, -1, -2, -2};
  int Y[8] = {2, -2, 1, -1, 2, -2, 1, -1};

  double knightProbability(int n, int k, int row, int col) {

    // dp[step][x][y]��ʾ��(x, y)����, ��Ծstep�κ����������ϵĸ���
    // Ҳ����˵, �𰸾���dp[k][row][col]
    vector<vector<vector<double>>> dp(
        k + 1, vector<vector<double>>(n, vector<double>(n)));

    // dp�߽�, �������κ�һ�����, ����Ծ, ��Ȼ����������, ����Ϊ1
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[0][i][j] = 1;
      }
    }

    // �Ե����ϵ���
    // dp[step][x][y]�͵���sum(dp[step - 1][x + biasX][y + biasY] / 8)
    // ������Ϊ������8��
    for (int step = 1; step <= k; step++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int x = 0; x < 8; x++) {
            int tx = i + X[x], ty = j + Y[x];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n) {
              continue;
            }
            dp[step][i][j] += (dp[step - 1][tx][ty] / 8);
          }
        }
      }
    }

    // ���ش�
    return dp[k][row][col];
  }
};