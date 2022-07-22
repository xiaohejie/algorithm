#include<iostream>
#include<vector>
using namespace std;
/*
	122. ������Ʊ�����ʱ�� II
		ʹ�ö�ά����
		dp[i][0]����i�콻��������û�й�Ʊ�ǵ��������
		dp[i][1]����i�콻�������ﻹ����һֻ��Ʊ���������
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//��Ҫ����һ����ά��������¼��i���������޹�Ʊʱ������������
		int n = prices.size();
		vector<vector<int>> f(n, vector<int>(2));
		//���г�ʼ��
		f[0][0] = 0;
		f[0][1] = -prices[0];
		//״̬ת�Ʒ���
		for (int i = 1; i < n; i++) {
			//������
			//��������û�еĻ���������ǰһ���Ѿ������˻�����ǰһ�������У�����������
			f[i][0] = max(f[i-1][0], f[i-1][1]+prices[i]);
			//�������ﻹ�еĻ���������ǰһ��Ļ����ǵ��칺����
			f[i][1] = max(f[i - 1][0] - prices[i], f[i - 1][1]);
		}
		return f[n - 1][0];
	}
};