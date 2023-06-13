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
// using list
class Solution {
    List<Integer>l=new ArrayList<>();
    void inorder(TreeNode root){
        if(root!=null){
            inorder(root.left);
            l.add(root.val);
            inorder(root.right);
        }
    }
    public int getMinimumDifference(TreeNode root) {
        inorder(root);
        int mini=Integer.MAX_VALUE;
        for(int i=1;i<l.size();i++){
            mini=Math.min(mini,l.get(i)-l.get(i-1));
        }
        return mini;
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
// using without list
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
    int mini=Integer.MAX_VALUE;
    int pre=Integer.MAX_VALUE;
    void inorder(TreeNode root){
        if(root!=null){
            inorder(root.left);
           if(pre!=Integer.MAX_VALUE) mini=Math.min(mini,root.val-pre);
            pre=root.val;
            inorder(root.right);
        }
    }
    public int getMinimumDifference(TreeNode root) {
        inorder(root);
        return mini;
    }
}
