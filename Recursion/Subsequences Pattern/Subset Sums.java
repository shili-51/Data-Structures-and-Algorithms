// https://www.geeksforgeeks.org/problems/subset-sums2234/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sums


class Solution {
    
    public void calculatesubsetSums(int index, ArrayList<Integer> arr, ArrayList<Integer> ans, int sum, int n){
        if(index == n){
            ans.add(sum);
            return;
        }
        
        // pick element
        calculatesubsetSums(index + 1, arr, ans, sum + arr.get(index), n);
        
        // not pick
        calculatesubsetSums(index + 1, arr, ans, sum, n);
        
    }
    
    
    ArrayList<Integer> subsetSums(ArrayList<Integer> arr, int n) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        calculatesubsetSums(0, arr, ans, 0, n);
        return ans;
    }
}
