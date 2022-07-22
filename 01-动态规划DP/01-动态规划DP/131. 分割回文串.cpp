#include<iostream>
#include<vector>
using namespace std;
/*
	131. 分割回文串
*/
class Solution {
	vector<vector<string>> ans;
	vector<string> path;
public:
	vector<vector<string>> partition(string s) {
		//创建动态容器
		int n = s.size();
		vector<vector<bool>> f(n, vector<bool>(n));
		//状态转移方程
		for (int j = 0; j < n; j++) {
			for (int i = 0; i <= j; i++) {
				if (i == j) {
					f[i][j] = 1;
				}
				else {
					f[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || f[i + 1][j - 1]);
				}
			}
		}
		//得到字符串中从哪里到哪里是回文子串，进行dfs
		dfs(s, 0, f);
		return ans;
	}
	void dfs(string s, int index, vector<vector<bool>> f) {
		//中止条件
		if (index == s.length()) {
			ans.push_back(path);
			return;
		}
		for (int i = index; i < s.length(); i++) {
			if (0 == f[index][i]) {
				continue;
			}
			else {
				path.push_back(s.substr(index, i - index + 1));
				dfs(s, i+1, f);
				//回溯
				path.pop_back();
			}
		}
	}
};