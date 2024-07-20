// https://leetcode.com/problems/subsets-ii/

class Solution {

    public void generateSubsets(int index, int[] nums, List<Integer> temp, Set<List<Integer>> combinations){

        if(index == nums.length){
            combinations.add(new ArrayList<>(temp));
            return;
        }

        // pick
        temp.add(nums[index]);
        generateSubsets(index + 1, nums, temp, combinations);
        temp.remove(temp.size() - 1);

        // not pick
        generateSubsets(index + 1, nums, temp, combinations);

    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Set<List<Integer>> combinations = new HashSet<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(nums);
        generateSubsets(0, nums, temp, combinations);
        List<List<Integer>> ans = new ArrayList<>(combinations);
       return ans;
    }
}
