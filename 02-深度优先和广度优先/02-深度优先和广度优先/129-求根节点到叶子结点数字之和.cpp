#include<iostream>
#include<vector>
using namespace std;
/*
	���ڵ㵽Ҷ�ڵ�����֮��
		ʹ��dfs
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
	int sumNumbers(TreeNode* root) {
	}
};