#include"LeetCode.h"

const int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

class Solution {
public:
    vector<vector<bool>> vis;
    int ans = 0;

    int movingCount(int m, int n, int k) {
        vis = vector<vector<bool>>(m, vector<bool>(n, false));

        // Ԥ�������ߵĸ���
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = !judge(k, i, j);
            }
        }

        // (0, 0)��ҲҪ�ж�һ���ܲ�����
        if (vis[0][0] == false) {
            dfs(0, 0, m, n);
        }

        return ans;
    }

    void dfs(int x, int y, const int m, const int n) {
        // ��������߹���, ���һ��
        ans++;
        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int tx = x + X[i], ty = y + Y[i];

            // ����vis = true�ĸ��Ӿ�ͣ��
            // ���õ���©��, ��һ���ߵ�������ӵ�·����Ϳ��ǹ��ߵ�������Ӻ�����������
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty]) {
                continue;
            }

            dfs(tx, ty, m, n);
        }
    }

    // ���־��е�judge����
    bool judge(int k, int x, int y) {
        int cnt = 0;
        while (x != 0) {
            cnt += (x % 10);
            x /= 10;
        }

        while (y != 0) {
            cnt += (y % 10);
            y /= 10;
        }

        return cnt <= k;
    }
};