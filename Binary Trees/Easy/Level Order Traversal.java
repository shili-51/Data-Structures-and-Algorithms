// https://leetcode.com/problems/binary-tree-level-order-traversal/


    public List<List<Integer>> levelOrder(TreeNode root) {

        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while(queue.isEmpty() == false){
            int sz = queue.size();
            List<Integer> temp = new ArrayList<>();
            while(sz > 0){
                TreeNode curr = queue.poll();
                temp.add(curr.val);
                if(curr.left != null) queue.add(curr.left);
                if(curr.right != null) queue.add(curr.right);
                sz--;
            }
            ans.add(new ArrayList<>(temp));
        }
        return ans;
    }
