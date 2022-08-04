#include<iostream>
#include<vector>
using namespace std;
/*
	926. 将字符串翻转到单调递增
*/
class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int dp0 = 0, dp1 = 1;		//表示第i个值为0或1的最小翻转数
		for (auto& ch : s) {
			int dp0N = dp0, dp1N = min(dp0, dp1);
			if (ch == '1') {
				dp0N++;
			}
			else {
				dp1N++;
			}
			dp0 = dp0N;
			dp1 = dp1N;
		}
		return min(dp0, dp1);
	}
};