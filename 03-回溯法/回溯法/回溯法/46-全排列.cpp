#include<iostream>
#include<vector>
using namespace std;
/*
	全排列：
*/

class Solution1 {
	vector<vector<int>> ans;
	void dfs(vector<int>& nums, vector<int> res, vector<int>& visited) {
		if (res.size() == nums.size()) {
			ans.push_back(res);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (visited[i] == 1) {
				//表明已经遍历过
				continue;
			}
			res.push_back(nums[i]);
			visited[i] = 1;
			dfs(nums, res, visited);
			res.pop_back();
			visited[i] = 0;
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> res;
		int n = nums.size();
		vector<int> visited(n, 0);
		dfs(nums, res, visited);
		return ans;
	}
};

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> res;
	void backTrack(vector<int>& nums, int start) {
		if (res.size() == nums.size()) {
			ans.push_back(res);
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			res.push_back(nums[start]);

		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		backTrack(nums, 0);
		return ans;
	}
};