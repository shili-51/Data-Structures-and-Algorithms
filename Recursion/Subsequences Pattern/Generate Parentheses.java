// https://leetcode.com/problems/generate-parentheses/

class Solution {
    void help(int open, int close, String temp, List<String> ans){
        if(open == 0 && close == 0) {
            ans.add(temp);
            return;
        }
        if(open != 0){
            help(open - 1, close, temp + "(", ans);  
        }
        if(close > open){
            help(open, close - 1, temp + ")", ans);
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        help(n, n, "", ans);
        return ans;
    }
}
