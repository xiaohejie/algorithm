#include<iostream>
#include<vector>
using namespace std;
/*
	120. 三角形最小路径和
		使用动态规划
*/
//从是上往下，还有一种是从下往上
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int m = triangle.size();
		cout << m << endl;
		//使用从上往下
		//创建动态容器
		vector<int> f(m + 1);		//这里考虑到（m+1）是因为下面有j+1；
		//初始化
		//状态转移方程
		for (int i = m - 1; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				f[j] = min(f[j], f[j + 1]) + triangle[i][j];
				// cout << f[j] <<  " ";
			}
			//cout << endl;
		}
		return f[0];
	}
};