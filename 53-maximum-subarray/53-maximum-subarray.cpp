class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxArray = nums[0];
        int maxSum = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            maxSum = max(nums[i], maxSum+nums[i]);
            maxArray = max(maxArray, maxSum);
        }
        
        return maxArray;
    }
};