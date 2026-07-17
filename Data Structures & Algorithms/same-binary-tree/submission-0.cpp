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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*>q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* n1 = q1.front();
            TreeNode* n2 = q2.front();
            if(n1-> val != n2 -> val) return false;
            q1.pop();
            q2.pop();
            if((n1 -> left == NULL) != (n2 -> left == NULL)) return false;
            if((n1 -> right == NULL) != (n2 -> right == NULL)) return false;
            if(n1 -> left) q1.push(n1 -> left);
            if(n1 -> right) q1.push(n1 -> right);
            if(n2 -> left) q2.push(n2 -> left);
            if(n2 -> right) q2.push(n2 -> right);
        }
        if(q1.empty() && q2.empty()) return true;
        return false;
    }
};
