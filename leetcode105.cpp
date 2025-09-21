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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    // pStart, pEnd: 前序遍历的起始和结束位置
    // iStart, iEnd: 中序遍历的起始和结束位置
    TreeNode* build(int pStart, int pEnd, int iStart, int iEnd) {
        if (pStart > pEnd || iStart > iEnd) return nullptr;
        // 前序遍历的第一个元素是根节点
        int rootVal = pre[pStart];
        TreeNode* root = new TreeNode(rootVal);
        // 在中序遍历中找到根节点的位置
        int rootPos = inorderMap[rootVal];
        // 计算左子树的节点数量
        int leftNums = rootPos - iStart;
        root->left = build(pStart + 1, pStart + leftNums, iStart, rootPos - 1);
        root->right = build(pStart + leftNums + 1, pEnd, rootPos + 1, iEnd);
        return root;
    }

private:
    map<int, int> inorderMap;  // 快速查找中序遍历中值的位置
    vector<int> pre;  // 存储前序遍历数组 避免递归中重复传递
};