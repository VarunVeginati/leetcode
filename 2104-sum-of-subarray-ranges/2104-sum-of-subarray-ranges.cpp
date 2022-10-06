class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        
        for(int i=0; i<nums.size(); i++) {
            int mx = nums[i];
            int mn = nums[i];
            for(int j=i+1; j<nums.size(); j++) {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                
                ans += mx-mn;
            }
        }
        
        return ans;
    }
};