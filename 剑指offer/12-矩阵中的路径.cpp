#include"LeetCode.h"

const int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

class Solution {
public:
    // ��dfs�Ĵ���
    string str;
    int n, r, c;

    // Ҫ�벻�߻�ͷ·, ����Ҫvis����
    vector<vector<bool>> vis;

    bool exist(vector<vector<char>>& board, string word) {
        // ��ʼ��
        str = word, n = str.size();
        r = board.size(), c = board[0].size();
        vis = vector<vector<bool>>(r, vector<bool>(c, false));

        // ��ÿ��λ��Ϊ��ͷ, ��������, �ѳɹ�һ�μ���return true
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (dfs(board, 0, i, j) == true) {
                    return true;
                }
            }
        }

        // û�ѵ�
        return false;
    }

    bool dfs(vector<vector<char>>& arr, int pos, int x, int y) {
        if (arr[x][y] != str[pos]) { // ·�߲�ͨ, return false
            return false;
        } 
        
        if (pos == n - 1 && arr[x][y] == str[pos]) {
            // ���һ���ַ�Ҳһ��, return true
            // ע�� "&& arr[x][y] == str[pos]" ���Բ�д, ������Ϊ���߼�����
            return true;
        }

        // ��ֹ�������߻�ͷ·�����޵ݹ�, ���յ���ջ���
        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int tx = x + X[i], ty = y + Y[i];
            // ����У��
            if (tx < 0 || tx >= r || ty < 0 || ty >= c || vis[tx][ty] == true) {
                continue;
            }

            // ����·��ͨ��, ֱ��return true, ��֦
            if (dfs(arr, pos + 1, tx, ty) == true) {
                return true;
            }
        }

        // ���ݷ��Ļָ��ֳ�
        vis[x][y] = false;

        // ����·�����з�·���߲�ͨ
        return false;
    }
};