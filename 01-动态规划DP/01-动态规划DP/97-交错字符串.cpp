#include<iostream>
#include<vector>
using namespace std;
/*
    97-�����ַ���
        ��̬�滮
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if (m + n != t) {
            return false;
        }
        /*���ж�̬�滮*/
        //������̬����
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        //�����ʼ״̬
        f[0][0] = true;     //s1��s2��Ϊ��
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        //״̬ת�Ʒ���
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i != 0 && s1[i] == s3[i+j]) {
                    f[i][j] = f[i][j]||f[i - 1][j];
                }
                if (j != 0 && s2[j] == s3[i+j]) {
                    f[i][j] = f[i][j] || f[i][j - 1];
                }
            }
        }
        return f[m][n];
    }
};