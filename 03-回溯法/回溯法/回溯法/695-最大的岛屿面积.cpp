#include<iotsream>
#include<vector>
using namespace std;
/*
	最大的岛屿面积：
		
*/
class Solution {
public:
	int m = 0, n = 0;
	int maxArea = 0;
	int dfs(int i, int j, vector<vector<int>>& grid) {
		//中止条件
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
			return;
		}

		grid[i][j] = 0;

		return 1 + dfs(i+1, j, grid) + dfs(i-1, j, grid) + dfs(i, j+1, grid) + dfs(i, j-1, grid);
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					int area = dfs(i, j, grid);
					maxArea = max(area, maxArea);
				}
			}
		}
		return maxArea;
	}
};