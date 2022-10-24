class Solution {
    public int[] findErrorNums(int[] nums) {
        Set<Integer> st = new HashSet<Integer>();
        
        int n = nums.length;
        int sum = (n*(n+1))/2;
        
        int[] res = new int[2];
        
        for(int i=0; i<n; i++) {
            sum -= nums[i];
            
            if(st.contains(nums[i]))
                res[0] = nums[i];
            
            st.add(nums[i]);
        }
        
        res[1] = sum+res[0];
        
        return res;
    }
}