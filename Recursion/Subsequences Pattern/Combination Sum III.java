// https://leetcode.com/problems/combination-sum-iii/

class Solution {

    public void comboSum(int index, int [] nums, int target, int n, int sum, List<List<Integer>> ans, List<Integer> temp, int sz){
        if(index == n){
            // System.out.println(temp);
            if(target == sum){
                if(temp.size() == sz){
                    ans.add(new ArrayList<>(temp));
                }
            }
            return;
        }

        // pick element
        temp.add(nums[index]);
        comboSum(index + 1, nums, target + nums[index], n, sum, ans, temp, sz);
        temp.remove(temp.size() - 1);

        // non pick
        comboSum(index + 1, nums, target, n, sum, ans, temp, sz);

    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        int [] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        comboSum(0, nums, 0, 9, n, ans, temp, k);
        return ans;
    }
}
