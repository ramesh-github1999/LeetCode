/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans;
    int cnt=0;
    void inorder(TreeNode root,int k){
        if(root==null) return;
        inorder(root.left,k);
        cnt++;
        if(cnt==k){
            ans=root.val;
            return;
        }
        inorder(root.right,k);
    }
    
    public int kthSmallest(TreeNode root, int k) {
         inorder(root,k);
        return ans;   
    }
}

 /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// Iterative methos using stack.
class Solution {
    
    public int kthSmallest(TreeNode root, int k) {
         Stack<TreeNode>st=new Stack<>();
        while(true){
            while(root!=null){
                st.add(root);
                root=root.left;
            }
            root=st.pop();
             if(--k==0) return root.val;
             root=root.right;
        }
        
    }
}

 
