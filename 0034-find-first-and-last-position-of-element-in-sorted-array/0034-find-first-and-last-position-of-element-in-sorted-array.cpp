class Solution {
public:
    bool binarySearch(vector<int> &nums, int l, int r, int target) {
        if(l<=r) {
            int mid = l + ((r-l)/2);
            
            if(target==nums[mid]) return true;
            else if(target>nums[mid]) return binarySearch(nums, mid+1, r, target);
            else return binarySearch(nums, l, mid-1, target);
        }
        
        return false;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binarySearch(nums, 0, nums.size()-1, target)) return {-1,-1};
        
        int l = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int u = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        
        return {l, u-1};
    }
};