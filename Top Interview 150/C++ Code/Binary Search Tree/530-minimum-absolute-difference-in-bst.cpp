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
    int mini=INT_MAX;
    int pre=INT_MAX;
    void inorder(TreeNode *root){
        if(root!=NULL){ inorder(root->left);
        if(pre!=INT_MAX) mini=min(root->val-pre,mini);
        pre=root->val;
        inorder(root->right);
    }
}
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mini;
    }
};
