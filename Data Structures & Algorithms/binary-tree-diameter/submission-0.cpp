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
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        return 1 + max(left, right);
    }
    int D = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int d = maxDepth(root -> left) + maxDepth(root -> right);
        D = max(D, d);
        diameterOfBinaryTree(root -> left);
        diameterOfBinaryTree(root -> right);
        return D;
    }
};
