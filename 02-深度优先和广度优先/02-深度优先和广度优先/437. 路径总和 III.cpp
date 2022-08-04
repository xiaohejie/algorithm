#include<iostream>
using namespace std;
/*
	437. 路径总和 III
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
	int dfs(TreeNode* root, int targetSum, int sum) {
		if (root == nullptr) {
			return 0;
		}
		int count = 0;
		sum += root->val;
		if (targetSum == sum) {
			count++;
		}
		//这里若是等于sum后还继续的原因是，看后面还有没有加起来还等于sum的分支
		count += dfs(root->left, targetSum, sum);
		count += dfs(root->right, targetSum, sum);
		return count;
	}
	int pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return 0;
		}
		return dfs(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
	}
};

class Solution2 {
	// 递归遍历树节点，判断是否为有效路径
	int dfs(struct TreeNode* root, int targetSum, long sum)
	{
		if (root == NULL)//叶子结点返回
		{
			return 0;
		}
		sum += (long)root->val;//统计节点值
		if (sum == targetSum)//是一个有效路径 +1
		{
			//再进行判断，以本节点还有没有有效路径
			return 1 + dfs(root->left, targetSum, sum) + dfs(root->right, targetSum, sum);
		}
		else//不是有效路径 +0
		{
			return dfs(root->left, targetSum, sum) + dfs(root->right, targetSum, sum);
		}
	}
	/*
	*int pathSum(struct TreeNode* root, int targetSum)
	int pathSum：寻找二叉树中路径个数
	struct TreeNode* root：树节点
	int targetSum：路径大小
	返回值：二叉树的路径数
	*/
	int pathSum(struct TreeNode* root, int targetSum) {
		if (root == NULL)
		{
			return 0;
		}
		//返回当前节点的路径数 + 左子树的路径数 + 右子树的路径数
		return dfs(root, targetSum, (long)0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
	}
};
