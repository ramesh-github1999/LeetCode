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
    vector<int>v;
    void inorder(TreeNode *root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    bool isSorted(vector<int>v){
        for(int i=1;i<v.size();i++){
            if(v[i-1]>=v[i]) return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return isSorted(v);
    }
};


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
class Solution2 {
public:
    TreeNode *pre=nullptr;
    bool inorder(TreeNode *root){
        if(root==nullptr) return true;
        if(!inorder(root->left)) return false;
        if(pre!=nullptr && root->val<=pre->val) return false;
        pre=root;
        return inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};
