#include <iostream>
#include<vector>
using namespace std;
/*
	��ͬ·����
		
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		//������̬����
		vector<vector<int>> dp(m, vector<int>(n, 0));
		if (m == 0 || n == 0) {
			return 0;
		}
		//���г�ʼ��
		for (int i = 0; i < m; i++) {
			//��ʼ����һ�У���Ϊ�����һ�����ֻ��һ��·����
			if (obstacleGrid[i][0] == 1) {
				//������ǰ���ϰ�����������ж����ܴﵽ
				break;
			}
			dp[i][0] = 1;	//���´ﵽ�õ��·����
		}
		for (int j = 0; j < n; j++) {
			//��ʼ����һ�У������һ�����Ҳֻ��һ��·����
			if (obstacleGrid[0][j] == 1) {
				//������ǰ���ϰ�����������ж����ܴﵽ
				break;
			}
			dp[0][j] = 1;
		}

		//״̬ת�Ʒ��̣����ݵ�һ�к͵�һ�е�·�������������ĵ㣩
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					//�����ǰ���ϰ��Ļ���ֱ������
					continue;
				}
				//��i�е�j�е�·��������dp[i][j - 1] + dp[i - 1][j]
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
		return dp[m - 1][n - 1];
	}
};