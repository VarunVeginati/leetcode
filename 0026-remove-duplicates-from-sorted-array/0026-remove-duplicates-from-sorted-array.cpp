class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int res = 1;
        int j = 0;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]>curr) {
                j++;
                curr = nums[i];
                nums[j] = nums[i];
                res++;
            }
        }
        
        return res;
    }
};