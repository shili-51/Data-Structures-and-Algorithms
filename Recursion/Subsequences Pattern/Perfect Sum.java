// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

//  Passing 1000 / 1020 cases on GFG need to optimise

class Solution{
    
    public void help(int index, int target, int arr[], int sum, int res[], ArrayList<Integer> temp){
        
        
        if(index == arr.length){
            if(target == sum){
                // System.out.println(temp);
                res[0]++;
            }
            return;
        }
        
        // pick
        temp.add(arr[index]);
        help(index + 1, target + arr[index], arr, sum, res, temp);
        temp.remove(temp.size() - 1);
        
        // Not Pick
        help(index + 1, target, arr, sum, res, temp);
        
        
    }
    

	public int perfectSum(int arr[],int n, int sum) 
	{ 
	    // Your code goes here
	    int res[] = new int[1];
	    ArrayList<Integer> temp = new ArrayList<>();
	    help(0, 0, arr, sum, res, temp);
	    return (res[0] % 1000000007);
	} 
}
