#include<iostream>
#include<vector>
using namespace std;
/*
	根节点到叶节点数字之和
		使用dfs
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
	vector<int> vec;
public:
	void dfs(TreeNode* root, int sum) {
		if (root == nullptr) {
			return;
		}
		sum = sum * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr) {
			vec.push_back(sum);
		}
		dfs(root->right, sum);
		dfs(root->left, sum);
	}
	int sumNumbers(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int sum = 0;
		dfs(root, sum);
		int ans = 0; 
		for (int i = 0; i < vec.size(); i++	) {
			cout << vec[i] << " ";
			ans += vec[i];
		}
		return ans;
	}
};