#include "LeetCode.h"

class Solution {
public: 
    vector<string> ans;
    vector<bool> vis;
    string temp;
    int n;
    vector<string> permutation(string s) {
        if (s.size() == 0) {
            return {};
        }

        this->n = s.size();
        vis.resize(n, false);
        sort(s.begin(), s.end());

        dfs(0, s);

        return ans;
    }

    void dfs(int idx, const string &s) {
        if (idx == n) {
            ans.push_back(temp);
        }

        for (int i = 0; i < n; i++) {
            // !vis[i - 1]����Ϊ:
            // ���ǰ���ظ����ַ��Ѿ������, ��ô��ʹ�ظ�Ҳ���Լ�����
            // ������5��s, ���ǳ���Ϊ1-5��s
            // ֻ��1��s�����, ������2��, Ȼ�������3��...
            // ��֤5��sֻ����һ��˳�����
            if (vis[i] == true || (i > 0 && s[i] == s[i - 1] && !vis[i - 1])) {
                continue;
            }

            temp.push_back(s[i]);
            vis[i] = true;
            dfs(idx + 1, s);
            vis[i] = false;
            temp.pop_back();
        }
    }
};