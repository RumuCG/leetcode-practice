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
// 对于任意一个节点 x，它的左子树所有节点的值 严格小于 x.val；
// 它的右子树所有节点的值 严格大于 x.val；
// 并且左右子树也必须分别是二叉搜索树。
// 因此对每个节点左右区间的最值进行比对
class Solution {
public:
    using ll = long long;
    bool dfs(TreeNode *now,ll mn,ll mx){
        if(now == nullptr) return true;
        bool ret = true;
        if(now->val <= mn || now->val >= mx) ret &= 0;
        ret &= dfs(now->left,mn,now->val);
        ret &= dfs(now->right,now->val,mx); 
        return ret;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,-(1ll << 32),(1ll << 32));
    }
};