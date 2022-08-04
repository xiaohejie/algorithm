#include<iostream>
#include<vector>
using namespace std;
/*
	��ͬ·��III��
		
*/
class Solution {
	int ans = 0;
public:
	void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int count) {
		//��ֹ����
		if (i < 0 ||i >= m || j < 0 || j >= n || grid[i][j] == -1 || grid[i][j] == -2) {
			return;
		}
		if (grid[i][j] == 2) {
			//��ʾ�ߵ����յ㣬��Ҫ�ж��Ƿ���������еĿշ���
			if (count == -1) {		//count==-1����Ϊ�����Ÿ���ʾΪ2
				ans++;
			}
			return;
		}

		//��¼�Ѿ�������
		grid[i][j] = -2;
		//�ݹ�
		dfs(grid, i + 1, j, m, n, count-1);
		dfs(grid, i - 1, j, m, n, count-1);
		dfs(grid, i, j + 1, m, n, count-1);
		dfs(grid, i, j - 1, m, n, count-1);

		//����
		grid[i][j] = 0;
		
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int count = 0;
		//���������пշ���
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					count++;
				}
			}
		}
		//�����ҵ���ʼλ��
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