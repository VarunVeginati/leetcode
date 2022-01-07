class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx_of_all = nums[0];
        int mx = nums[0];
        int mn = nums[0];
        int mx_dummy = nums[0];
        int mn_dummy = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            mx = max(nums[i], max(mx_dummy*nums[i], mn_dummy*nums[i]));
            mn = min(nums[i], min(mx_dummy*nums[i], mn_dummy*nums[i]));
            
            mx_dummy = mx;
            mn_dummy = mn;
            
            mx_of_all = max(mx, mx_of_all);
        }
        
        return mx_of_all;
    }
};