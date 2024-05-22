// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            s.insert({nums[i]});
        }

        int res = 1;
        for(int i=0; i<n; i++){

            // if nums[i] - 1 exists in array, that means nums[i] cannot 
            // start the consecutive subsequence, we need to find starting number 
            // which will start forming consecutive subsequence
            if(s.find(nums[i] - 1) != s.end()) continue;

            // starting number of consecutive subsequence
            if(s.find(nums[i] + 1) != s.end()){
                int curr = 1;
                while(s.find(nums[i] + curr) != s.end()){
                    curr++;
                }
                res = max(res, curr);
            }
        }
        if(n == 0) return 0;
        else return res;
    }
};
