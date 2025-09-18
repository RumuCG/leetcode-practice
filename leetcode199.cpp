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
 // 层序遍历取最右边的即可
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        queue<TreeNode*> p;
        q.push(root);
        vector<int> tmp;
        while(q.size()){
            TreeNode* it = q.front();
            if(it->left != nullptr) p.push(it->left);
            if(it->right != nullptr) p.push(it->right);
            tmp.push_back(it->val);
            q.pop();
            if(q.empty()) {
                swap(p,q);
                ans.push_back(tmp.back());
                tmp.clear();
            }
        }
        return ans;
    }
};