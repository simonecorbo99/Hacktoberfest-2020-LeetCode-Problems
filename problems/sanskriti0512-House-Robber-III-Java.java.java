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
    public int rob(TreeNode root) {
        HashMap<TreeNode, Integer> h=new HashMap<>();
        return robhelper(root,h);
    }
    public int robhelper(TreeNode root,  HashMap<TreeNode, Integer> h){
        if(root==null)
            return 0;
        if(h.containsKey(root))
            return h.get(root);
        int smallans1 = robhelper(root.left,h)+robhelper(root.right,h);
        int smallans2 = root.val;
        if(root.left!=null)
            smallans2 = smallans2 + robhelper(root.left.left,h)+robhelper(root.left.right,h);
         if(root.right!=null)
            smallans2 = smallans2 + robhelper(root.right.left,h)+robhelper(root.right.right,h);
        h.put(root,Math.max(smallans1,smallans2));
        return h.get(root);
    }
}