#include<iostream>
#include<vector>
using namespace std;
/*
	122. 买卖股票的最佳时机 II
		使用二维数组
		dp[i][0]：第i天交易完手里没有股票是的最大利润
		dp[i][1]：第i天交易完手里还持有一只股票的最大利润
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//需要创建一个二维数组来记录第i天手里有无股票时，最大利润情况
		int n = prices.size();
		vector<vector<int>> f(n, vector<int>(2));
		//进行初始化
		f[0][0] = 0;
		f[0][1] = -prices[0];
		//状态转移方程
		for (int i = 1; i < n; i++) {
			//卖或不卖
			//当天手里没有的话，可能是前一天已经卖掉了或者是前一天手里有，当天卖掉的
			f[i][0] = max(f[i-1][0], f[i-1][1]+prices[i]);
			//当天手里还有的话，可能是前一天的或者是当天购进的
			f[i][1] = max(f[i - 1][0] - prices[i], f[i - 1][1]);
		}
		return f[n - 1][0];
	}
};