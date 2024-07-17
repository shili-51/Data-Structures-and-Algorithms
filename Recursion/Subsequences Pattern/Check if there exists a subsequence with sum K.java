// https://www.naukri.com/code360/problems/subset-sum_630213?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

// Recursion Solution gives TLE - need to optimise

public class Solution {

    public static boolean help(int index, int target, int n, int sum, int []a){
        if(index == a.length){
            if(target == sum) return true;
            return false;
        }

        // pick
        target = target + a[index];
        if(help(index + 1, target, n, sum, a) == true) return true;
        target = target - a[index];

        // not pick
        if(help(index + 1, target, n, sum, a) == true) return true;

        return false;
    }
    public static boolean isSubsetPresent(int n, int k,int []a) {
        return help(0, 0, n, k, a);
    }
}
