// https://leetcode.com/problems/max-consecutive-ones-iii/

# count number of 0s in each window, if count0 <= k calculate ans, if count0 exceeds k remove 0s from front

class Solution {
    public int longestOnes(int[] nums, int k) {
        int i = 0;
        int count0 = 0;
        int ans = 0;
        for(int j = 0; j < nums.length; j++){
            if(nums[j] == 0) count0++;
            if(count0 <= k) ans = Math.max(ans, j - i + 1);
            else if(count0 > k){
                while(count0 > k){
                    if(nums[i] == 0) count0--;
                    i++;
                }
            }
        }
        return ans;
    }
}
