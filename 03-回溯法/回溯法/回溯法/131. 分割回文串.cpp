#include<iostream>
#include<vector>
using namespace std;
/*
	131. 分割回文串
		先使用动态规划，记录字符串字符之间能不能构成回文
		在使用回溯法，进行遍历
*/
class Solution {
private:
	int len = 0;
	vector<vector<bool>>f;
	vector<vector<string>> ans;
	vector<string>path;
public:
	void dfs(string s, int index) {
		//中止条件
		if (index == len) {
			ans.push_back(path);
			return;
		}
		for (int i = index; i < len; i++) {
			if (f[index][i] == 0) {
				//构不成回文串
				continue;
			}
			//构成回文串
			path.push_back(s.substr(index, i - index + 1));
			//进行下一个位置的dfs
			dfs(s, i + 1);
			//恢复现场
			path.pop_back();
		}
	}
	vector<vector<string>> partition(string s) {
		len = s.length();
		//初始化
		f = vector<vector<bool>>(len, vector<bool>(len));
		//状态方程(要从列开始遍历)
		for (int j = 0; j < len; j++) {
			for (int i = 0; i <= j; i++) {
				if (i == j) {
					f[i][j] = 1;
				}
				else {
					//后面是因为有可能f[i+1][j-1]不存在
					f[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || f[i + 1][j - 1]);
				}
			}
		}
		//进行回溯
		dfs(s, 0);
		return ans;
	}
};