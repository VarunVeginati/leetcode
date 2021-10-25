class Solution {
public:
    int binary_search(vector<int> nums, int l, int r, int target) {
        while(r>=l) {
            int mid = (r+l)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[l] < nums[mid] && target < nums[mid] && target >= nums[l]) return binary_search(nums, l, mid-1, target);
            
            if(nums[l] > nums[mid] && (target < nums[mid] || target >= nums[l])) return binary_search(nums, l, mid-1, target);
            
            return binary_search(nums, mid+1, r, target);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size()-1, target);
    }
};