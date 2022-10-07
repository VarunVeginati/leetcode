class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size()-i-1; j++) {
                nums[j] = (nums[j]+nums[j+1])%10;
            }
        }
        
        return nums[0]%10;
    }
};