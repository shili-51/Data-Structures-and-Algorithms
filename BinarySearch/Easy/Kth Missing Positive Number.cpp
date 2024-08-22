// https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
    public int findKthPositive(int[] arr, int k) {
        int start = 0;
        int end = arr.length - 1;
        int lower = 1, upper = k, ele_start = 1;
        while(start <= end){
            int mid = start + (end - start)/2;

            // difference between actual value at this index and present value at this index gives missing elements till this index
            int val = Math.abs(arr[mid] - (mid + 1));
            if(val < k){
                lower = val;  // elements missing till current index
                ele_start = arr[mid]; // lower value of range in which missing element lies
                start = mid + 1;
            }else {
                upper = val; // upper value of range in which missing element lies
                end = mid - 1;
            }
        }
        
        System.out.println("lower: " + lower);
        System.out.println("upper: " + upper);
        System.out.println("ele_start: " + ele_start);

        // k = 1, lower = 1, upper = 1, arr = [2], ele_start = 2
        if(lower == upper && lower != ele_start) return ele_start - 1;
        for(int i = lower + 1; i <= upper; i++){

            // range of missing element (lower, upper)
            // ele_start - checking each missing element in range for getting kth missing value
            ele_start = ele_start + 1;
            if(i == k) break;
        }

        return ele_start;
        
    }
}
