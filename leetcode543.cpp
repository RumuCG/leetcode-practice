/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 左右子树深度之和就是经过该节点的最大直径 最大直径可能不经过根节点
class Solution {
public:
    int ans = 0;
     int get_deep(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = get_deep(root->left);
        int right = get_deep(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        get_deep(root);
        return ans;
    }
};