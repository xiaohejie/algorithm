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