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
    public boolean isLeaf(TreeNode root) {
        return root.left==null && root.right==null;
    }
    
    public boolean dfs(int target, TreeNode root) {
        if(root==null) return false;
        if(target==root.val && isLeaf(root)) return true;
        
        return dfs(target-root.val, root.left) || dfs(target-root.val, root.right);
    }
    
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return dfs(targetSum, root);
    }
}