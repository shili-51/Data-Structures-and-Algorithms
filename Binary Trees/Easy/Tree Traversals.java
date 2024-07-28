// https://www.naukri.com/code360/problems/tree-traversal_981269?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&count=25&page=1&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM

import java.util.List;
import java.util.ArrayList;
public class Solution {

    public static void Inorder(List<Integer> InorderList, TreeNode root){
        if(root == null) return;
        Inorder(InorderList, root.left);
        InorderList.add(root.data);
        Inorder(InorderList, root.right);
    }

     public static void Preorder(List<Integer> PreorderList, TreeNode root){
        if(root == null) return;
        PreorderList.add(root.data);
        Preorder(PreorderList, root.left);
        Preorder(PreorderList, root.right);
    }

     public static void Postorder(List<Integer> PostorderList, TreeNode root){
        if(root == null) return;
        Postorder(PostorderList, root.left);
        Postorder(PostorderList, root.right);
        PostorderList.add(root.data);
    }
    
    
    public static List<List<Integer>> getTreeTraversal(TreeNode root) {
        
        List<List<Integer>> Traversal = new ArrayList<>();
        List<Integer> InorderList = new ArrayList<>();
        List<Integer> PreorderList = new ArrayList<>();
        List<Integer> PostorderList = new ArrayList<>();

        Inorder(InorderList, root);
        Preorder(PreorderList, root);
        Postorder(PostorderList, root);

        Traversal.add(InorderList);
        Traversal.add(PreorderList);
        Traversal.add(PostorderList);

        return Traversal;
    }
}
