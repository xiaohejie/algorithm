#include<iostream>
#include<vector>
using namespace std;
/*
	376-摆动排序
*/
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		//创建动态容器，记录长度
		vector<int> up(n), down(n);
		//进行初始化
		up[0] = down[0] = 1;
		//状态转移方程
		for (int i = 1; i < n; i++) {
			if (nums[i] > nums[i-1]) {
				//更新
				up[i] = max(up[i-1], down[i-1]+1);
				down[i] = down[i - 1];
			}
			else if(nums[i] < nums[i-1]){
				//更新
				up[i] = up[i - 1];
				down[i] = max(down[i-1], up[i-1] + 1);
			}
			else {
				//不变
				up[i] = up[i - 1];
				down[i] = down[i - 1];
			}
		}
		return max(up[n-1], down[n-1]);
	}
};