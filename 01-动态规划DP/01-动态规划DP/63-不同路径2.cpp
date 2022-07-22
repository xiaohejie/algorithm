#include<iostream>
#include<vector>
using namespace std;
/*
	63-不同路径2
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //创建动态容器
        vector<vector<int>> f(m, vector<int>(n));
        //初始化
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0]) {
                break;
            }
            f[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i])break;
            f[0][i] = 1;
        }
        //状态转移方程
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    //有障碍
                    f[i][j] = 0;
                }
                else {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};