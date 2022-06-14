#include<iostream>
#include<vector>
using namespace std;
/*
	统计子岛屿：
		把grid1中为海洋的板块、grid2中为陆地的板块找出，并另grid2中的改为海洋
		然后在进行寻找
*/
class Solution {
public:
	void dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
		//终止条件（终止条件要考虑全面）
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
			//直接终止，不需要进行其他操作
			return;
		}

		//将该地方置位海洋
		grid[i][j] = 0;
		//然后进行dfs
		dfs(grid, i - 1, j, m, n);
		dfs(grid, i + 1, j, m, n);
		dfs(grid, i, j - 1, m, n);
		dfs(grid, i, j + 1, m, n);
		//不需要进行回溯
	}
	
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		int m = grid1.size(), n = grid1[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				//找出上述所说条件
				if (grid1[i][j] == 0 && grid2[i][j] == 1) {
					//进行dfs
					dfs(grid2, i, j, m, n);
				}
			}
		}
		int count = 0;
		//遍历，找出子岛屿
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid2[i][j] == 1) {
					count++;
					dfs(grid2, i, j, m, n);
				}
			}
		}
		return count;
	}
};