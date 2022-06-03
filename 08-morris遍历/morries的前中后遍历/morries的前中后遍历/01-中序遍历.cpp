#include<iostream>
using namespace std;

// Morris 中序遍历
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
        mostright = cur->left; // cur左孩子
        // 如果当前节点的左子树存在
        if (mostright != nullptr) {
            // 找到左子树最右的节点，并让mostright指向它
            // mostright.right != null可以保证第一次定位mostright
            // mostright.right != cur可以保证第二次定位mostright
            while (mostright->right != nullptr && mostright->right != cur) {
                mostright = mostright->right;
            }
            // 如果左子树最右节点的右孩子为空，那么让其指向cur,cur往左走
            if (mostright->right == nullptr) {
                mostright->right = cur;
                cur = cur->left;
                continue;
            }
            else { // mostright的right指向cur（之前设置过），right重新置为空
                mostright->right = nullptr;
            }
        }
        // 左子树已处理完（左子树为空或已经访问过），然后打印当前的根节点的值
        cout << cur->val << " ";
        // 如果当前节点的左子树不存在或已经访问过，那么cur往右走
        cur = cur->right;
    } // while
}