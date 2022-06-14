#include<iostream>
#include<vector>
using namespace std;
/*
	ͳ���ӵ��죺
		��grid1��Ϊ����İ�顢grid2��Ϊ½�صİ���ҳ�������grid2�еĸ�Ϊ����
		Ȼ���ڽ���Ѱ��
*/
class Solution {
public:
	void dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
		//��ֹ��������ֹ����Ҫ����ȫ�棩
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
			//ֱ����ֹ������Ҫ������������
			return;
		}

		//���õط���λ����
		grid[i][j] = 0;
		//Ȼ�����dfs
		dfs(grid, i - 1, j, m, n);
		dfs(grid, i + 1, j, m, n);
		dfs(grid, i, j - 1, m, n);
		dfs(grid, i, j + 1, m, n);
		//����Ҫ���л���
	}
	
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		int m = grid1.size(), n = grid1[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				//�ҳ�������˵����
				if (grid1[i][j] == 0 && grid2[i][j] == 1) {
					//����dfs
					dfs(grid2, i, j, m, n);
				}
			}
		}
		int count = 0;
		//�������ҳ��ӵ���
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