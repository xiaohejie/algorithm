#include<iostream>
#include<vector>
using namespace std;
/*
	给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
	找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
	你可以按 任意顺序 返回这些组合。

	candidates 中的 同一个数字可以无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

	对于给定的输入，保证和为 target 的不同组合数少于 150 个。

*/
class Solution1 {
	vector<vector<int>> ans;
	vector<int> res;
	void dfs(vector<int>& candidates, int target, int sum, int index) {
		if (target == sum) {
			ans.push_back(res);
			return;
		}
		if (sum > target) {
			return;
		}
		for (int i = index; i < candidates.size(); i++) {
			sum += candidates[i];
			res.push_back(candidates[i]);
			dfs(candidates, target, sum, i);			//这里要注意递归的index
			sum -= candidates[i];
			res.pop_back();
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int sum = 0;
		dfs(candidates, target, sum, 0);
		return ans;
	}
};

class Solution {
public:
	vector<vector<int>>res; //记录答案
	vector<int>path;   //记录路径

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		dfs(candidates, 0, target);
		return res;
	}

	void dfs(vector<int>& c, int u, int target)
	{
		if (target < 0) return;   //递归边界
		if (target == 0)
		{
			res.push_back(path);  //记录答案
			return;
		}
		for (int i = u; i < c.size(); i++) {
			if (c[i] <= target)
			{
				path.push_back(c[i]);   //加入路径数组中
				dfs(c, i, target - c[i]);// 因为可以重复使用，所以还是i
				path.pop_back();        //回溯，恢复现场
			}
		}
	}


	//void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>res, int index) {
	//	//中止回溯的条件
	//	if (index == candidates.size()) {
	//		return;
	//	}
	//	if (target == 0) {
	//		ans.push_back(res);
	//		return;
	//	}
	//	//可以选择跳过当前数
	//	dfs(candidates, target, ans, res, index + 1);
	//	//也可以选择当前数字
	//	if (target - candidates[index] >= 0) {
	//		res.push_back(candidates[index]);
	//		dfs(candidates, target - candidates[index], ans, res, index);
	//		res.pop_back();				//回溯，恢复现场
	//	}

	//}
	//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	//	vector<vector<int>> ans;
	//	vector<int> res;
	//	dfs(candidates, target, ans, res, 0);
	//	return ans;
	//}
};