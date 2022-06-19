#include<iostream>
#include<vector>
using namespace std;
/*
    97-交错字符串
        动态规划
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if (m + n != t) {
            return false;
        }
        /*进行动态规划*/
        //创建动态容器
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        //定义初始状态
        f[0][0] = true;     //s1和s2都为空
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        //状态转移方程
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