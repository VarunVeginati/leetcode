class Solution {
public:
    int start = -1;
    int end = -1;
    
    void bS(vector<int> &nums, int target, int left, int right) {
        if(left<=right) {
            int mid = left+((right-left)/2);
            
            if(nums[mid]==target) {
                if(start == -1) {
                    if(mid==0 || nums[mid-1]<target) start = mid;
                    else {
                        bS(nums, target, left, mid-1);
                    }
                }
                if(end == -1) {
                    if(mid==nums.size()-1 || nums[mid+1]>target) end = mid;
                    else {
                        bS(nums, target, mid+1, right);
                    }
                }
            } else if(nums[mid]>target) {
                bS(nums, target, left, mid-1);
            } else if(nums[mid]<target) {
                bS(nums, target, mid+1, right);
            }
         }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        bS(nums, target, 0, nums.size()-1);
        
        return {start, end};
    }
};