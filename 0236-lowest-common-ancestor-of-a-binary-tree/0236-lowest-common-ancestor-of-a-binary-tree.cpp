/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left != NULL && right != NULL) return root;
        
        if ((root == p || root == q) && (left == p || left == q)) return root;
        
        if ((root == p || root == q) && (right == p || right == q)) return root;
        
        if (root == p || root == q) return root;
        
        return left != NULL ? left : right;
    }
};