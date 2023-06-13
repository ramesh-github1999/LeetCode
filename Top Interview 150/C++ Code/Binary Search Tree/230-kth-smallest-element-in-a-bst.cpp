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
// using a vector.
class Solution {
public:
   
    void kth(TreeNode *root,vector<int>&v){
        if(root->left!=NULL) kth(root->left,v);
        v.push_back(root->val);
        if(root->right!=NULL) kth(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
       kth(root,v);
        return v[k-1];
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
// using without any vector
class Solution2 {
public:
    int ans;
    void inorder(TreeNode *root,int &k){
        if(!root) return;
        inorder(root->left,k);
        k--;
        if(k==0){
            ans=root->val;
            return;
        }
        inorder(root->right,k);
    }
        
          
    int kthSmallest(TreeNode* root, int k) {
         inorder(root,k);
        return ans;
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
//using iteration method

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *>st;
        while(root!=NULL || !st.empty()){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            if(--k==0) return root->val;
            root=root->right;
        }
        return 0;
    }
};
