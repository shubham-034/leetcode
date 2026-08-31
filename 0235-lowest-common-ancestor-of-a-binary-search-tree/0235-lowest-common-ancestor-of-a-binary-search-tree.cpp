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
        if(root==NULL){
            return NULL;
        }
        //leftSubtree:
        // If both nodes are smaller than root, LCA must be in the left subtree
        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        //rightSubtree:
        // If both nodes are greater than root, LCA must be in the right subtree
        if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        //root:
        // If one node is on the left and one is on the right (or root matches p or q),
        // the current root IS the lowest common ancestor.
        return root;
    }
};