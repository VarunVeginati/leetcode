class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for(int i=0; i<nums.size(); i++) {
            total += nums[i];
        }
        
        int sum = total-x;
        
        if(sum<0) return -1;
        
        int left = 0;
        int right = 0;
        
        int sub_array_sum = nums[0];
        
        int min_operations = INT_MAX;
        
        while(right<nums.size()) {
            if(sub_array_sum == sum) {
                int a = nums.size() - (right-left+1);
                min_operations = min(min_operations, a);
                right++;
                if(right<nums.size()) sub_array_sum += nums[right];
            } else if(sub_array_sum<sum) {
                right++;
                if(right<nums.size()) sub_array_sum += nums[right];
            } else {
                sub_array_sum -= nums[left];
                left++;
            }
        }
        
        return min_operations == INT_MAX ? -1: min_operations;
    }
};