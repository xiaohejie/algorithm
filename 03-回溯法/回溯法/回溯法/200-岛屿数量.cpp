#include<iostream>
#include<vector>
using namespace std;
/*
	岛屿数量：
		
*/
class Solution {
public:
	int m = 0, n = 0;
	int res = 0;
	void dfs(int i, int j, vector<vector<char>>& grid) {
		//回溯中止条件
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
			return;
		}
		grid[i][j] = ' 0';

		dfs(i+1, j, grid);
		dfs(i-1, j, grid);
		dfs(i, j+1, grid);
		dfs(i, j-1, grid);

		//后面不需要进行回溯（自己想原因）

	}
    int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					res++;
					dfs(i, j, grid);
				}
			}
		}
		return res;
    }
};