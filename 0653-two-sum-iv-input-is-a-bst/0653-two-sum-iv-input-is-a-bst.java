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
    List<Integer> list = new ArrayList<Integer>();
    
    public void dfs(TreeNode root) {
        if(root==null) return;
        
        list.add(Integer.valueOf(root.val));
        dfs(root.left);
        dfs(root.right);
    }
    
    public boolean findTarget(TreeNode root, int k) {
        dfs(root);
        Set<Integer> s = new HashSet<Integer>();
        
        for(int i=0; i<list.size(); i++) {
            int target = k-list.get(i);
            if(s.contains(target)) return true;
            
            s.add(list.get(i));
        }
        
        return false;
    }
}