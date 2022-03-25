#include"LeetCode.h"

/**
 * �ⷨһ: ����
 * ʱ�临�Ӷ� -> O(n), ���ǻ᲻�ϵ��ؽ��Ϳ����ַ���
 * �ռ临�Ӷ� -> O(n), ���ǻ᲻�ϵ��ؽ��Ϳ����ַ���
 */
class Solution {
public:
    string replaceSpace(string s) {
        // ������Ŀ��Χ, ��Ҫ����
        int n = s.size();
        if (n == 0) {
            return "";
        }

        // ��ԭ���滻������, �½�һ���ַ���ans
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                ans += "%20";
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};

/**
 * �ⷨ��: Ԥ�����Ż�
 * ʱ�临�Ӷ� -> O(n)
 * �ռ临�Ӷ� -> O(n)
 */
class Solution {
public:
    string replaceSpace(string s) {
        // ������Ŀ��Χ, ��Ҫ����
        int n = s.size();
        if (n == 0) {
            return "";
        }

        // ��ǰͳ�ƿո�����cnt
        int cnt = 0;
        for (const auto &c : s) {
            if (c == ' ') {
                cnt++;
            }
        }

        // ans�ַ����ĳ�����cnt * 2 + s.size()
        string ans(cnt * 2 + s.size(), '\0');
        
        int i = 0;
        for (const auto& c : s) {
            if (c == ' ') {
                ans[i++] = '%', ans[i++] = '2', ans[i++] = '0';
            } else {
                ans[i++] = c;
            }
        }

        return ans;
    }
};