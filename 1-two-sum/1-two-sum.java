class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> hm = new HashMap<Integer,Integer>();
        int[] res = {};
        
        for(int i=0; i<nums.length; i++) {
            int k = target-nums[i];
            
            if(hm.containsKey(k)) {
                int[] res1 = {hm.get(k), i};
                return res1;
            }
            
            hm.put(nums[i], i);
        }
        
        return res;
    }
}