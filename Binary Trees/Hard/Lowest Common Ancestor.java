// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        // if found p and q node or null return that node
        if(root == null || root.val == p.val || root.val == q.val) return root;

        TreeNode lside = lowestCommonAncestor(root.left, p, q);
        TreeNode rside = lowestCommonAncestor(root.right, p, q);

        // if from any one of the side or from both sides you receive null - that means no p and q lies in that part, 
        // return not null val or null val(lside == null && rside == null) - any one among p and q lies in that part
        if(lside == null) return rside;
        else if(rside == null) return lside;

        // if from both sides there is not null value, that node is LCA
        else{
            return root;
        }
        
    }
}
