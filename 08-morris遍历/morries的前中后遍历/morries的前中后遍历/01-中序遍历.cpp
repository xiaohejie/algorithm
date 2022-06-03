#include<iostream>
using namespace std;

// Morris �������
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
static void morrisIn(TreeNode* root) {
    if (root == nullptr)
        return;
    TreeNode* cur = root;
    TreeNode* mostright = nullptr;
    while (cur != nullptr) {
        mostright = cur->left; // cur����
        // �����ǰ�ڵ������������
        if (mostright != nullptr) {
            // �ҵ����������ҵĽڵ㣬����mostrightָ����
            // mostright.right != null���Ա�֤��һ�ζ�λmostright
            // mostright.right != cur���Ա�֤�ڶ��ζ�λmostright
            while (mostright->right != nullptr && mostright->right != cur) {
                mostright = mostright->right;
            }
            // ������������ҽڵ���Һ���Ϊ�գ���ô����ָ��cur,cur������
            if (mostright->right == nullptr) {
                mostright->right = cur;
                cur = cur->left;
                continue;
            }
            else { // mostright��rightָ��cur��֮ǰ���ù�����right������Ϊ��
                mostright->right = nullptr;
            }
        }
        // �������Ѵ����꣨������Ϊ�ջ��Ѿ����ʹ�����Ȼ���ӡ��ǰ�ĸ��ڵ��ֵ
        cout << cur->val << " ";
        // �����ǰ�ڵ�������������ڻ��Ѿ����ʹ�����ôcur������
        cur = cur->right;
    } // while
}