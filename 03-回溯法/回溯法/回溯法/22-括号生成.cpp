#include<iostream>
#include<vector>
using namespace std;
/*
	括号生成：
	使用回溯法：
		当左括号小于n时{
			就要生成左括号
			然后递归
			回溯
		}
		当右括号小于左括号时{
			就要生成右括号
			然后递归
			回溯
		}
*/
class Soultion1 {
	vector<string> ans;
	void dfs(int left, int right, string s, int n) {
		if (left + right == 2 * n) {
			ans.push_back(s);
			return;
		}
		//左括号不够
		if (left < n) {
			s += "(";
			dfs(left+1, right, s, n);
			//进行回溯
			s.pop_back();
		}
		//右括号少于左括号
		if (right < left) {
			s += ")";
			dfs(left, right + 1, s, n);
			//进行回溯
			s.pop_back();
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		string s = "";
		dfs(0, 0, s, n);
		return ans;
	}
};
class Solution {
	vector<string> ans;
public:
	void backtrack(int left, int right, int n, string& s) {
		//中止条件
		if (left + right == n * 2) {
			ans.push_back(s);
			return;
		}
		if (left < n) {
			s += "(";
			backtrack(left + 1, right, n, s);
			s.pop_back();
		}
		if (right < left) {
			s += ")";
			backtrack(left, right + 1, n, s);
			s.pop_back();
		}
	}
	vector<string> generateParenthesis(int n) {
		string s = "";
		backtrack(0, 0 , n, s);
		return ans;
	}
};