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
 // 利用先序遍历的特点，根 -> 左 -> 右，因此对于当前节点，他的右子树的前驱节点应该是左子树的最右侧的节点，因此依次对节点处理，把左子树
 // 放到右子树的位置，右子树放到左子树最右侧的右孩子上，这样每个节点最多访问两次，时间复杂度为O(n) 空间复杂度为O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *tmp = root;
        while(root){
            if(root -> left){
                tmp = root -> left;
                while(tmp -> right) tmp = tmp -> right;
                tmp -> right = root -> right;
                root -> right = root -> left;
                root -> left = nullptr;
            }
            root = root -> right;
        }
        
    }
};