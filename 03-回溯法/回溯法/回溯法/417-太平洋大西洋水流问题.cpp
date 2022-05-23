#include<iostream>
#include<vector>
using namespace std;
/*
	̫ƽ�������ˮ�����⣺
		˼·��
			1�������Ե��ʼdfs��������ͨ��̫ƽ��ĵĴ�½��飬���ұ�Ե��½��鿪ʼdfs��������ͨ��������Ĵ�½���
			2�����ϱ�Ե��ʼdfs��������ͨ��̫ƽ��ĵĴ�½��飬���±�Ե��½��鿪ʼdfs��������ͨ��������Ĵ�½���
			Ȼ�����dfs�ж�
*/
class Solution {
	/*
		˼·�ǶԵģ���������
	*/
private:
	int directions[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };			//����
	int row = 0, col = 0;				//����������	
	vector<vector<int>> heights;		//����ȫ������
public:
	//�����������
	//void dfs(int i, int j, vector<vector<bool>> canReach) {
	//	if (canReach[i][j]) {
	//		return;
	//	}
	//	canReach[i][j] = true;	//δ���ʹ����б��
	//	//Ȼ�������������
	//	for (auto d : directions) {
	//		int nextR = i + d[0];
	//		int nextC = j + d[1]; 
	//		//���dfs���½ڵ�λ��Խ���˻�����߶�û��ǰ��ڵ�߶ȸ�
	//		if (nextR < 0 || nextR > row || nextC < 0 || nextC >col || heights[i][j] > heights[nextR][nextC]) {
	//			continue;
	//		}
	//		//����Ļ����еݹ����
	//		dfs(nextR, nextC, canReach);
	//	}
	//}
	void dfs(int row, int col, vector<vector<bool>>& ocean) {
		int m = ocean.size();
		int n = ocean[0].size();
		if (ocean[row][col]) {
			return;
		}
		ocean[row][col] = true;
		for (int i = 0; i < 4; i++) {
			int newRow = row + directions[i][0], newCol = col + directions[i][1];
			if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
				dfs(newRow, newCol, ocean);
			}
		}
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		this->heights = heights;
		vector<vector<int>> res;
		/*if (heights.size() == 0) {
			return res;
		}*/
		row = heights.size();
		col = heights[0].size();
		vector<vector<bool>> canReachPacific(row, vector<bool>(col, false));
		vector<vector<bool>> canReachAtlantic(row, vector<bool>(col, false));

		//�����Ե��ʼdfs��������ͨ��̫ƽ��ĵĴ�½��飬���ұ�Ե��½��鿪ʼdfs��������ͨ��������Ĵ�½���
		for (int i = 0; i < row; i++) {
			dfs(i, 0, canReachPacific);
			dfs(i, col - 1, canReachAtlantic);
		}
		//���ϱ�Ե��ʼdfs��������ͨ��̫ƽ��ĵĴ�½��飬���±�Ե��½��鿪ʼdfs��������ͨ��������Ĵ�½���
		for (int j = 0; j < col; j++) {
			dfs(0, j, canReachPacific);
			dfs(row - 1, j, canReachAtlantic);
		}

		//�������еİ��Ѽ�����ͨ��̫ƽ��������ͨ��������İ��������
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
					res.push_back({ i, j });
				}
			}
		}
		return res;
	}
};