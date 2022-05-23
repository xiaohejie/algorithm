#include<iostream>
#include<vector>
using namespace std;
/*
	È«ÅÅÁĞ£º
*/
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