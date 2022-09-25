class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int curr = -1;
        int index = -1;
        
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i]>=curr) {
                curr = nums[i];
            } else {
                index = i;
                break;
            }
        }
        
        if(index!=-1) {
            int i=index+1;
            
            while(i<nums.size() && nums[i]>nums[index]) i++;
            
            nums[index] = nums[i-1]^nums[index];
            nums[i-1] = nums[i-1]^nums[index];
            nums[index] = nums[i-1]^nums[index];
        }
        
        reverse(nums.begin()+index+1, nums.end());
    }
};