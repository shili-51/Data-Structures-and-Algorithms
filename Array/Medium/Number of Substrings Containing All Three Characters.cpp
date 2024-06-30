// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp = {
            {'a' , 0},
            {'b' , 0},
            {'c', 0}
        };
        int i = 0;
        int j = 0;
        int count = 0;
        int n = s.length();
        while(j < n){
            mp[s[j]]++;
            while(mp['a'] + mp['b'] + mp['c'] >= 3 & (mp['a'] >= 1 & mp['b'] >= 1 & mp['c'] >= 1)){
                count = count + (n - j);  // if till j there is a required string then from j till n there will be strings satisfying same condition.
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};
