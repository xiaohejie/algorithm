#include<iostream>
#include<vector>
using namespace std;
/*
	不同路径III：
		
*/
class Solution {
	int ans = 0;
public:
	void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int count) {
		//中止条件
		if (i < 0 ||i >= m || j < 0 || j >= n || grid[i][j] == -1 || grid[i][j] == -2) {
			return;
		}
		if (grid[i][j] == 2) {
			//表示走到了终点，需要判断是否遍历完所有的空方格
			if (count == -1) {		//count==-1是因为结束放个表示为2
				ans++;
			}
			return;
		}

		//记录已经遍历过
		grid[i][j] = -2;
		//递归
		dfs(grid, i + 1, j, m, n, count-1);
		dfs(grid, i - 1, j, m, n, count-1);
		dfs(grid, i, j + 1, m, n, count-1);
		dfs(grid, i, j - 1, m, n, count-1);

		//回溯
		grid[i][j] = 0;
		
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int count = 0;
		//计算网格中空方格
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					count++;
				}
			}
		}
		//遍历找到起始位置
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					dfs(grid, i, j, m, n, count);
				}
			}
		}
		return ans;
	}
};