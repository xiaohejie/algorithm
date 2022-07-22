#include<iostream>
#include<vector>
using namespace std;
/*
	91-解码方法:
		使用动态规划
		初始：字符串为空就返回空, f[0] = 1;
		//条件f[i-1]的成立条件：f[i]在1到9之间；f[i-2]的成立条件：f[i]在10到26之间
		f[i] = f[i-1] + f[i-2];
*/
class Solution {
public:
	int numDecodings(string s) {
		//设置动态容器
		int len = s.length();
		vector<int> f(len + 1);
		//进行初始化
		f[0] = 1;
		s = ' ' + s;
		//状态转移方程
		for (int i = 1; i <= len; i++ ) {
			int a = s[i] - '0';
			int b = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (a > 0 && a < 10 ) {
				f[i] = f[i - 1];
			}
			if (b >= 10 && b <= 26) {
				f[i] += f[i - 2];
			}
		}
		return f[len];
	}
};