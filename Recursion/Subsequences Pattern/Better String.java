// https://www.geeksforgeeks.org/problems/better-string/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=better-string

// This Solution passes 1014/1116 test cases we need to optimise this further

    public static void calculateUniqueSubsequences(int index, String s, Set<String> subseqSet, String temp){
        if(index == s.length()){
            subseqSet.add(temp);
            return;
        }
        
        // pick element
        calculateUniqueSubsequences(index + 1, s, subseqSet, temp + s.charAt(index));
        
        // not pick element
        calculateUniqueSubsequences(index + 1, s, subseqSet, temp);

    }
    
    public static String betterString(String str1, String str2) {
        Set<String> subseqSetstr1 = new HashSet<>();
        Set<String> subseqSetstr2 = new HashSet<>();
        calculateUniqueSubsequences(0, str1, subseqSetstr1, "");
        calculateUniqueSubsequences(0, str2, subseqSetstr2, "");
        if(subseqSetstr1.size() >= subseqSetstr2.size()) return str1;
        else return str2;
    }
}
