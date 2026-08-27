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
    int minDiff=INT_MAX;
    int preVal=-1;
    void inOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        //leftSubTree
        inOrder(root->left);
        //root
        if(preVal!=-1){
            minDiff=min(minDiff,root->val-preVal);
        }
        preVal=root->val;
        //rightSubtree
        inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }
};