class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int i = 0;
        int j = 0;
        int k = p.length();
        int len = s.length();
        unordered_map<char,int>mp;
        for(int i = 0; i < k; i++){
            mp[p[i]]++;
        }
        int count = mp.size();

        // count represents count of distinct characters in string p

        while(j < len){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count --;
            }

            if(j - i + 1 < k) j++;

            else if(j - i + 1 == k){
                if(count == 0) ans.push_back(i);

                // while sliding the window if ith element is there in string p, to ignore its calculation in previous window, try to re generate its count in map similar to original size 
                if(mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) count++;  // if each distinct char of string p is there.
                }

                i++;
                j++;
            }
        }
        return ans;
    }
};
