#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	全排列（全排列1和2还有组合）：
		多理解理解
*/
class Solution1 {
	vector<vector<int>> ans;

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		
	}
};

class Solution {
public:
	vector<vector<int>> res;
	vector<int> ans;
	vector<int> visited;
	void dfs(vector<int>& nums) {
		if (ans.size() - 1 == nums.size() - 1) {
			res.push_back(ans);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			//剪枝操作
			if (visited[i] == 1) {		//表示当前字符已经访问过
				continue;
			}
			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 1) {	//去重操作
				continue;
			}

			ans.push_back(nums[i]);
			visited[i] = 1;
			dfs(nums);
			//回溯
			ans.pop_back();
			visited[i] = 0;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int n = nums.size();
		visited.resize(n);
		sort(nums.begin(), nums.end());
		dfs(nums);
		return res;
	}
};