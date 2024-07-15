// https://leetcode.com/problems/subsets/


class Solution {

    void help(int i, List<Integer> temp, List<List<Integer>> ans, int[] nums){
        if(i >= nums.length) {
            ans.add(new ArrayList<> (temp));
            return;
        }

        // pick element 
        temp.add(nums[i]);
        help(i + 1, temp, ans, nums);

        // not pick
        temp.remove(temp.size() - 1);
        help(i + 1, temp, ans, nums);

    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        help(0, temp, ans, nums);
        return ans;
    }
}
