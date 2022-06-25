class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()==1) return true;
        int cnt = 0;
        
        if(nums[1]<nums[0]) {
            cnt++;
            nums[0] = nums[1];
        }
        
        for(int i=2; i<nums.size(); i++) {
            if(nums[i]<nums[i-1]) {
                cnt++;
                if(nums[i-2]>nums[i]) {
                    nums[i]=nums[i-1];
                } else {
                    nums[i-1] = nums[i];
                }
            }
        }
        
        return cnt<=1;
    }
};