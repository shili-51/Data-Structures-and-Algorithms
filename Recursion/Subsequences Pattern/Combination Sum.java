// https://leetcode.com/problems/combination-sum/

class Solution {
    public void help(int index, int target, List<Integer> temp, List<List<Integer>> ans, int[] candidates, int sum){

        // base condition
        if(index == candidates.length){
            if(target == sum){
                System.out.println(temp);
                ans.add(new ArrayList<>(temp));    // this I need to remember
            }
            return;
        }

        else if(target <= sum){

            // picking duplicate elements is also allowed
            temp.add(candidates[index]);
            target = target + candidates[index];
            help(index, target, temp, ans, candidates, sum);
            temp.remove(temp.size() - 1);
            target = target - candidates[index];
        }

        // not picking element or target exceeds sum
        help(index + 1, target, temp, ans, candidates, sum);

    }


    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList();
        List<Integer> temp = new ArrayList();
        help(0, 0, temp, ans, candidates, target);
        return ans;
    }
}
