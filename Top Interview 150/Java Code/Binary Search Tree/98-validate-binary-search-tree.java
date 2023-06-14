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
     List<Integer>l=new ArrayList<>();
    void inorder(TreeNode root){
        if(root==null) return;
        inorder(root.left);
        l.add(root.val);
        inorder(root.right);
    }
    
     boolean isSorted(List<Integer>l){
        for(int i=1;i<l.size();i++){
            if(l.get(i-1)>=l.get(i)) return false;
        }
        return true;
    }
    
    public boolean isValidBST(TreeNode root) {
        inorder(root);
        return isSorted(l);
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
class Solution2 {
    TreeNode pre=null;
    boolean inorder(TreeNode root){
        if(root==null) return true;
        if(!inorder(root.left)) return false;
        if(pre!=null && root.val<=pre.val) return false;
        pre=root;
        return inorder(root.right);
    }

    public boolean isValidBST(TreeNode root) {
        return inorder(root);
    }
}
