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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,unsigned long long>>q;
        int maxWidth=0;
        q.push({root,0});
        while(q.size()>0){
            unsigned long long startIdx=q.front().second;
            unsigned long long endIdx=q.back().second;
            int currentSize=q.size();
            maxWidth=max(maxWidth,(int)(endIdx-startIdx+1));
            for(int i=0;i<currentSize;i++){
                TreeNode* currNode=q.front().first;
                unsigned long long currNodeIdx=q.front().second;
                q.pop();
                if(currNode->left){
                    q.push({currNode->left,(2*currNodeIdx)+1});
                }
                if(currNode->right){
                    q.push({currNode->right,(2*currNodeIdx)+2});
                }
            }
        }
        return maxWidth;

    }
};