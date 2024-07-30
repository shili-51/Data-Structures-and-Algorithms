// https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
    public int help(TreeNode root, int[] res){
        if(root == null) return 0;

        int lh = help(root.left, res);
        int rh = help(root.right, res);

        // root is not a part of diameter - [1 + max(lh, rh)]
        int temp = 1 + Math.max(lh, rh);

        // root is part of diameter - [1 + lh + rh]
        int ans = Math.max(1 + lh + rh, temp);

        // res
        res[0] = Math.max(res[0], ans);

        // passing child answer to parent
        return temp;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        int[] res = new int[]{0};
        help(root, res);
        return res[0] - 1;
    }
}
