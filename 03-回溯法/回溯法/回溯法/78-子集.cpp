#include<iostream>
#include<vector>
using namespace std;
/*
	78. ×Ó¼¯
*/
class Solution {
	vector<vector<int>> ans;
	vector<int> res;
	void dfs(vector<int>& nums, int start, int len) {
		if (start == len) {
			return;
		}
		for (int i = start; i < len; i++) {
			res.push_back(nums[i]);
			ans.push_back(res);
			dfs(nums, i+1, len);
			res.pop_back();
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int len = nums.size();
		dfs(nums, 0 , len);
		ans.push_back({});
		return ans;
	}
};