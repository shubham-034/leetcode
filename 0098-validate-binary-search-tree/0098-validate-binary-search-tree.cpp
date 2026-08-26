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
    bool isValid(TreeNode* root,long long int min,long long int max){
        if(root==NULL){
            return true;
        }
        if(min!=LLONG_MIN && root->val<=min){
            return false;
        }
        if(max!=LLONG_MAX && root->val>=max){
            return false;
        }
        bool leftSubTree=isValid(root->left,min,root->val);
        bool rightSubTree=isValid(root->right,root->val,max);
        return leftSubTree && rightSubTree;
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }   
};