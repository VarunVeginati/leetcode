class Solution {
public:
    int bS(vector<int> &nums, int l, int r, int target) {
        if(l<=r) {
            int mid = l+(r-l)/2;
            
            if(nums[mid]==target) return mid;
            
            if(target>nums[mid]) return bS(nums, mid+1, r, target);
            return bS(nums, l, mid-1, target);
        }
        
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++) {
            int idx = bS(numbers, i+1, numbers.size()-1, target-numbers[i]);
            if(idx != -1) return {i+1, idx+1};
        }
        
        return {};
    }
};