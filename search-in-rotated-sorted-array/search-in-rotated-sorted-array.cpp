class Solution {
public:
    int bS(vector<int> &nums, int l, int r, int target) {
        if(l<=r) {
            int mid = l + ((r-l)/2);
            
            if(nums[mid] == target) return mid;
            
            if(nums[mid] < nums[r]) {
                if(target>nums[mid] && target <= nums[r]) return bS(nums, mid+1, r, target);
                else return bS(nums, l, mid-1, target);
            } else if(nums[l] <= nums[mid]) {
                if(target>=nums[l] && target < nums[mid]) return bS(nums, l, mid-1, target);
                else return bS(nums, mid+1, r, target);
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return bS(nums, 0, nums.size()-1, target);
    }
};