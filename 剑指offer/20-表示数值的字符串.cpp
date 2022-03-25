#include"LeetCode.h"

/**
 * ʱ�临�Ӷ� -> O(n), ����һ�鼴��, ָ�벻��ͷ
 * �ռ临�Ӷ� -> O(1)
 */
class Solution {
public:
    bool isNumber(string s) {
        // s�ĳ��ȴ��ڵ���1, �������пմ�

        int n = s.size();

        // ��ȡ�õ�ָ��, ����ͷ
        int idx = 0;        

        // 1. ȥ���ײ��ո�
        while (s[idx] == ' ') {
            idx++;
        }

        // 2. ��ȡ��ѧ��������ǰ�벿��(û�ÿ�ѧ���������Ƕ�ȡȫ����ֵ)
        // �����Ķ�������С���������ͷ���false
        
        // 2.1 ��ȡһ������
        // ������������ǿ�ѧ��������ǰ�벿��, Ҳ����ֻ��С������������, �����ǿյ�Ҳû����
        // flag���¼�Ƿ��ȡ��������
        bool flag = readInt(s, idx);

        // 2.2 �����С�������, ��ôС����ǰ��ֻҪһ�����������־Ϳ�����, ʹ�û���������ж�
        if (s[idx] == '.') {
            idx++;
            // С������治���и���, ʹ��readUInt
            flag = readUInt(s, idx) || flag;
        }

        // 2.3 ������������С��, ����false 
        if (flag == false) {
            return false;
        }

        // 3. �ж��Ƿ�ʹ���˿�ѧ������, ���ʹ���˾Ͷ�ȡһ������
        // ��������Ҫ�������ͷ���false
        if (s[idx] == 'e' || s[idx] == 'E') {
            idx++;
            bool flag = readInt(s, idx);
            if (flag == false) {
                return false;
            }
        }

        // 4. ���������е�����, ˵��ûʹ�ÿ�ѧ���������߿�ѧ��������ʽ�Ϸ�
        // ʣ�µ����ݱ���ȫ���ǿո�, ֻҪдһ���ǳ��򵥵��ж��߼�����
        while (idx < n) {
            if (s[idx] != ' ') {
                return false;
            }
            idx++;
        }

        return true;
    } 

    // ��ȡһ������, ����ָ���ƶ���������������һ��λ��
    bool readInt(const string& s, int &idx) {
        if (s[idx] == '+' || s[idx] == '-') {
            idx++;
        }

        return readUInt(s, idx);
    }

    // ��ȡһ���Ǹ�����, ����ָ���ƶ����Ǹ�������������һ��λ��
    bool readUInt(const string& s, int& idx) {
        int cnt = 0;
        while (s[idx] >= '0' && s[idx] <= '9') {
            idx++;
            cnt++;
        }

        return cnt > 0; 
    }
};




