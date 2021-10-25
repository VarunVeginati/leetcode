class Solution {
public:
    int binary_search(vector<int> nums,int l,int r,int target) {
        while(r>=l) {
            int mid = (r+l)/2;
            
            if(nums[mid] == target) return mid;
            
            if(mid == 0 && target < nums[mid]) return mid;
            if(mid == nums.size()-1 && target > nums[mid]) return mid+1;
            if(mid != 0 && target > nums[mid-1] && target<nums[mid]) return mid;
            
            if(nums[mid] < target) return binary_search(nums, mid+1, r, target);
            
            return binary_search(nums, l, mid-1, target);
        }
        return -1;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size()-1, target);
    }
};