// https://leetcode.com/problems/palindrome-partitioning/


---- Process substrings in BFS manner, only proceed if the current substring is a palindrome to process the remaining string

class Solution {

    public boolean isPalindrome(int start, int end, String s){
        while(start <= end){
            if(s.charAt(start) != s.charAt(end)) return false;
            start++;
            end--;
        }
        return true;
    }

    public void palindromePartitions(String s, int index, List<String> temp, List<List<String>> ans){
        if(index == s.length()){
            ans.add(new ArrayList<String>(temp));
            return;
        }

        for(int i = index; i < s.length(); i++){
            if(isPalindrome(index,i,s)){
                String curr = s.substring(index, i + 1);
                temp.add(curr);
                palindromePartitions(s, i + 1, temp, ans);
                temp.remove(temp.size() - 1);
            }
        }

    }


    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<List<String>>();
        List<String> temp = new ArrayList<String>();
        palindromePartitions(s,0,temp,ans);
        return ans;
    }
}
