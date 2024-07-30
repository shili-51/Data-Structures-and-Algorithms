// https://leetcode.com/problems/same-tree/

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if((p == null && q != null) || (p != null && q == null)) return false;
        else if(p == null && q == null) return true;
        return ((p.val == q.val) && (isSameTree(p.left, q.left)) && (isSameTree(p.right, q.right)));
    }
}
