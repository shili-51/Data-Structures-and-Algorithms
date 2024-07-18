// https://leetcode.com/problems/combination-sum-ii/

// Below code gives TLE - 172/176

class Solution {

    public void help(int index, int target, int sum, int[] candidates, List<Integer> temp, List<List<Integer>> ans, HashSet<List<Integer>> combinationSet){
        
        if(index == candidates.length){
            if(target == sum){
                if(combinationSet.contains(temp) == false){
                    ans.add(new ArrayList<>(temp));
                    combinationSet.add(new ArrayList<>(temp));
                }
            }
            return;
        }

        else if(target <= sum){
            // pick element
            temp.add(candidates[index]);
            help(index + 1, target + candidates[index], sum, candidates, temp, ans, combinationSet);
            temp.remove(temp.size() - 1);
        }

        // not pick
        help(index + 1, target, sum, candidates, temp, ans, combinationSet);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        HashSet<List<Integer>> combinationSet = new HashSet<>();
        Arrays.sort(candidates); 
        help(0, 0, target, candidates, temp, ans, combinationSet);
        // System.out.println(combinationSet);
        return ans;
    }
}
