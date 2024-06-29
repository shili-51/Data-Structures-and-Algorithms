// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxfreq = INT_MIN;
        int ans = 0;
        unordered_map<char,int>mp;
        while(j < s.size()){
            mp[s[j]]++;
            maxfreq = max(maxfreq, mp[s[j]]);

            // j - i + 1 = current window size
            // maxfreq - element which we should not flip
            //  current window size - maxfreq = minfreq element which should be flipped k times
            if(j - i + 1 - maxfreq <= k){
                ans = max(ans, j - i + 1);
            }else{
                while(j - i + 1 - maxfreq > k){
                    mp[s[i]]--;
                    maxfreq = max(maxfreq, mp[s[i]]);
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
