#include<iostream>
#include<vector>
using namespace std;
/*
	926. ���ַ�����ת����������
*/
class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int dp0 = 0, dp1 = 1;		//��ʾ��i��ֵΪ0��1����С��ת��
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