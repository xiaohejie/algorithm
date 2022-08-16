#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	90. ×Ó¼¯ II
*/
class Solution {
	vector<vector<int>> ans;
	vector<int> res;
	void dfs(vector<int>& nums, int start) {
		if (start == nums.size()) {
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			if (i > start && nums[i-1] == nums[i]) {
				continue;
			}
			res.push_back(nums[i]);
			ans.push_back(res);
			dfs(nums, i+1);
			res.pop_back();
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		ans.push_back(res);
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return ans;
	}
};