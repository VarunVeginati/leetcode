class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> hm = new HashMap<Integer,Integer>();
        
        for(int i=0; i<nums.length; i++) {
            if(hm.containsKey(nums[i])) {
                if(i-hm.get(nums[i]) <=k) return true;
            }
            hm.put(nums[i], i);
        }
        
        return false;
    }
}