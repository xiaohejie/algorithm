#include<iostream>
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

	}
};