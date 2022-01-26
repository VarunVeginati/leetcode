class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        int zeros = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) zeros++;
            else {
                j++;
                nums[j]=nums[i];
            }
        }
        
        int n = nums.size()-1;
        
        while(zeros>0) {
            nums[n]=0;
            n--;
            zeros--;
        }
        
        return;
    }
};