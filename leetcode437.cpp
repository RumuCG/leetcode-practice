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
 // 写出表达式 sum - pre = target => pre = sum - target 只需要存路径上的前缀个数，用总和减去前缀就是该节点符号题意的路径
class Solution {
public:
    using ll = long long;
    int res = 0;
    unordered_map<ll,int> presum;
    void dfs(TreeNode *it,int targetSum,ll sum){
        if(it == NULL) return;
        sum += it -> val;
        res += presum[sum - targetSum];
        presum[sum] ++;
        dfs(it -> left,targetSum,sum);
        dfs(it -> right,targetSum,sum);
        presum[sum] --;
    }
    int pathSum(TreeNode* root, int targetSum) {
        presum[0] = 1;
        dfs(root,targetSum,0);
        return res;
    }
};