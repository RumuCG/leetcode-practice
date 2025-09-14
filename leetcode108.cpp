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
 // 简单题 递归划分区间构建avl即可
class Solution {
public:
    TreeNode* dfs(int l, int r,vector<int> & nums){
        if(l > r) return nullptr;
        int mid = l + r >> 1;
        TreeNode *tmp = new TreeNode(nums[mid]);
        tmp->left = dfs(l,mid - 1,nums);
        tmp->right = dfs(mid + 1,r,nums);
        return tmp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int siz = nums.size() - 1;
        return dfs(0,siz,nums);       
    }
};