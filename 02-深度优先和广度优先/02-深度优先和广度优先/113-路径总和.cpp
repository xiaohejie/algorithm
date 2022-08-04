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
	vector<vector<int>> ans;
	vector<int> path;
	void dfs(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return;
		}
		path.push_back(root->val);
		targetSum -= root->val;
		//判断
		if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
			ans.push_back(path);
		}
		dfs(root->left, targetSum);
		dfs(root->right, targetSum);
		path.pop_back();
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return ans;
		}
		dfs(root, targetSum);
		return ans;
	}
};