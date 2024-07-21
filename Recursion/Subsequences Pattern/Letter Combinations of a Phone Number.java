// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {

    public void help(int i, String digits, String temp, List<String> ans, HashMap<Character, String> mp){
        if(temp.length() == digits.length()){
            ans.add(new String (temp));
            return;
        }


        int len = mp.get(digits.charAt(i)).length();

        for(int j = 0; j < len; j++){
            help(i + 1, digits, temp + mp.get(digits.charAt(i)).charAt(j), ans, mp);
        }

    }

    public List<String> letterCombinations(String digits) {

        HashMap<Character, String> mp = new HashMap<>();
        mp.put('2', "abc");
        mp.put('3', "def");
        mp.put('4', "ghi");
        mp.put('5', "jkl");
        mp.put('6', "mno");
        mp.put('7', "pqrs");
        mp.put('8', "tuv");
        mp.put('9', "wxyz");

        List<String> ans = new ArrayList<>();
        String temp = "";

        if(digits.length() == 0) return new ArrayList<>();

        help(0, digits, temp, ans, mp);

        return ans;
        
    }
}
