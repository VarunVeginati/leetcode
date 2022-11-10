class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_array = nums[0];
        int max_sum = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            max_sum = max(nums[i], max_sum+nums[i]);
            max_array = max(max_array, max_sum);
        }
        
        return max_array;
    }
};