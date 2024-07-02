// https://leetcode.com/problems/subarrays-with-k-different-integers/

// calculate subarrays with at most k different integers - subarrays with at most (k -1) different integers

class Solution {
public:
    int help(vector<int> &nums, int k){
        int i = 0, j = 0, ans = 0;
        unordered_map<int,int>mp;
        while(j < nums.size()){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k) - help(nums,k-1);
    }
};
