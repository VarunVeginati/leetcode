class Solution {
public:
    int binary_searh(vector<int> nums,int l, int r, int target, bool first) {
        while(r>=l) {
            int mid = (r+l)/2;
            
            if(nums[mid] == target) {
                if (first) {
                    if(mid == 0) return mid;
                    if(nums[mid-1] == target) return binary_searh(nums, l, mid-1, target, true);
                } else {
                    if(mid == nums.size()-1) return mid;
                    else if(nums[mid+1] == target) return binary_searh(nums, mid+1, r, target, false);
                }
                return mid;
            }
            
            if(nums[mid] < target) return binary_searh(nums, mid+1, r, target, first);
            
            return binary_searh(nums, l, mid-1, target, first);
        }
        
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binary_searh(nums, 0, nums.size()-1, target, true);
        if(first == -1) return {-1,-1};
        int second = binary_searh(nums, 0, nums.size()-1, target, false);
        return {first,second};
    }
};