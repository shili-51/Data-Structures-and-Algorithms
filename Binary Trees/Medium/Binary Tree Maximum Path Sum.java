// https://leetcode.com/problems/binary-tree-maximum-path-sum/


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

    public int help(TreeNode root, int[] res){
        if(root == null) return 0;

        int lsum = help(root.left, res);
        int rsum = help(root.right, res);

        // temp = max (
        // only root value - if root value is positive and lsum & rsum is negative (negative value for both left and right child)
        // root.val + max(lsum, rsum) - to pass ans of child node to parents
        )

        int temp = Math.max(root.val, root.val + Math.max(lsum, rsum));



        // ans = max (
        // temp
        // root.val + lsum + rsum - if root itself wants to become part of ans
        )

        int ans = Math.max(temp, root.val + lsum + rsum);

        
        res[0] = Math.max(res[0], ans);

        return temp;
    }


    public int maxPathSum(TreeNode root) {
        int[] res = new int[]{0};
        res[0] = Integer.MIN_VALUE;
        help(root, res);
        return res[0];
    }
}
