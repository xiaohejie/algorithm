#include<iostream>
#include<vector>
using namespace std;
/*
	53. 最大子数组和
        使用动态规划
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto& x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};