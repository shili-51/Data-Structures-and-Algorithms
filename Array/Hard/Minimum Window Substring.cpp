// https://leetcode.com/problems/minimum-window-substring/

//        IN HASHMAP
// if frequency of any element becomes -ve, it means in current substring we have extra characters matching with characters in "t" string
// else if frequency of any element becomes +ve, it means we need to acquire that "t" string element from string "s" in futher iteration
// else if frequency of any element becomes 0, that means in our current substring we have exactly same number of elements of "t" string, length of current substring may or may not be equal to "t" string

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int minLen = INT_MAX;
        int start = 0;
        if(t.length() > s.length()) return ans;
        unordered_map<char,int>mp;
        for(int i = 0; i < t.length(); i++){
            mp[t[i]]++;
        }
        int count = mp.size();
        int i = 0, j = 0;
        string temp = "";
        while(j < s.length()){
            temp += s[j];
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            while(count == 0 && i <= j){
                    if(count == 0) {
                        if(j - i + 1 < minLen){
                            minLen = j - i + 1;
                            start = i;
                        }
                    }
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1) count++;
                    }
                    temp.erase(0,1);
                    i++;
                }
            j++;
        }
    if(minLen == INT_MAX) return "";
    else return s.substr(start, minLen);
    }
};
