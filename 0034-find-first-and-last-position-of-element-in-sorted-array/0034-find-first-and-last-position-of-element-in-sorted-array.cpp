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
    
    int lowerBound(vector<int>&nums, int l, int r, int target) {
        if(l<=r) {
            int mid = l + ((r-l)/2);
            
            if(target <= nums[mid]) return lowerBound(nums, l, mid-1, target);
            else return lowerBound(nums, mid+1, r, target);
        }
        
        return min(r+1, (int) nums.size()-1);
    }
    
    int upperBound(vector<int>&nums, int l, int r, int target) {
        if(l<=r) {
            int mid = l + ((r-l)/2);
            
            if(target >= nums[mid]) return upperBound(nums, mid+1, r, target);
            else return upperBound(nums, l, mid-1, target);
        }
        
        return max(0,l-1);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binarySearch(nums, 0, nums.size()-1, target)) return {-1,-1};
        
        // int l = lowerBound(nums, 0, nums.size()-1, target);
        // int u = upperBound(nums, 0, nums.size()-1, target);
        int l = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int u = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        
        return {l, u-1};
    }
};