#include<iostream>
using namespace std;
/*
	437. ·���ܺ� III
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
		//�������ǵ���sum�󻹼�����ԭ���ǣ������滹��û�м�����������sum�ķ�֧
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
	// �ݹ�������ڵ㣬�ж��Ƿ�Ϊ��Ч·��
	int dfs(struct TreeNode* root, int targetSum, long sum)
	{
		if (root == NULL)//Ҷ�ӽ�㷵��
		{
			return 0;
		}
		sum += (long)root->val;//ͳ�ƽڵ�ֵ
		if (sum == targetSum)//��һ����Ч·�� +1
		{
			//�ٽ����жϣ��Ա��ڵ㻹��û����Ч·��
			return 1 + dfs(root->left, targetSum, sum) + dfs(root->right, targetSum, sum);
		}
		else//������Ч·�� +0
		{
			return dfs(root->left, targetSum, sum) + dfs(root->right, targetSum, sum);
		}
	}
	/*
	*int pathSum(struct TreeNode* root, int targetSum)
	int pathSum��Ѱ�Ҷ�������·������
	struct TreeNode* root�����ڵ�
	int targetSum��·����С
	����ֵ����������·����
	*/
	int pathSum(struct TreeNode* root, int targetSum) {
		if (root == NULL)
		{
			return 0;
		}
		//���ص�ǰ�ڵ��·���� + ��������·���� + ��������·����
		return dfs(root, targetSum, (long)0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
	}
};
