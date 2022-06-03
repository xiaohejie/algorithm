#include<iostream>
#include<vector>
using namespace std;
/*
	路径总和II：
		深度优先遍历 + 回溯
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

	}
};