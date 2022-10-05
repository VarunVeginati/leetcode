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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth==1) return new TreeNode(val, root, null);
        TreeNode res = root;
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int step = 2;
        
        while(!q.isEmpty() && step<depth) {
            step++;
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                TreeNode curr = q.poll();
                
                if(curr.left != null) q.add(curr.left);
                if(curr.right != null) q.add(curr.right);
            }
        }
        
        while(!q.isEmpty()) {
            TreeNode curr = q.poll();
            TreeNode left = curr.left;
            TreeNode right = curr.right;
            
            curr.left = new TreeNode(val, left, null);
            curr.right = new TreeNode(val, null, right);
        }
        
        return res;
    }
}