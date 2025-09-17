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
 // BST 中序遍历就是递增序列
class Solution {
public:
    int ans = 0; // 当前已经访问的节点数
    int ret = 0; // 第 k 小的值
    bool dfs(TreeNode* tmp, int k) {
        if (!tmp) return false;
        if (dfs(tmp->left, k)) return true;
        ans++;
        if (ans == k) {
            ret = tmp->val;
            return true; 
        }
        return dfs(tmp->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ret;
    }
};
