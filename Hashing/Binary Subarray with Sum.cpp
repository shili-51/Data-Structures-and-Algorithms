// https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int pre_sum = 0;
        int res = 0;
        int n = nums.size();
        unordered_map<int,int>preSum;
        for(int i = 0; i < n; i++){
            pre_sum += nums[i];
            if(pre_sum == k) res++;
            if(preSum.find(pre_sum - k) != preSum.end()){
                res = res + preSum[pre_sum - k];
            }
            preSum[pre_sum]++;
        }
        return res;
        
    }
};
