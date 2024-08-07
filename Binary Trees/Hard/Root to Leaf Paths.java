// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

class Solution {
    
    public static void RootToLeafPath(Node root, ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> ans){
        if(root != null && root.left == null && root.right == null){
            temp.add(root.data);
            ans.add(new ArrayList<Integer>(temp));
            temp.remove(temp.size() - 1);
            return;
        }
        else if(root == null) return;
        
        temp.add(root.data);
        RootToLeafPath(root.left , temp, ans);
        RootToLeafPath(root.right , temp, ans);
        temp.remove(temp.size() - 1);
    }
    
    
    public static ArrayList<ArrayList<Integer>> Paths(Node root) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> temp = new ArrayList<Integer>();
        RootToLeafPath(root, temp, ans);
        return ans;
    }
}
