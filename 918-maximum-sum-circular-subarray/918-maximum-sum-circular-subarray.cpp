class Solution {
public:
    int kadance(vector<int> nums, int i, int j, int sign) {
        int max_segment = INT_MIN;
        int max_all = INT_MIN;
        
        for(int k=i; k<=j; k++) {
            max_segment = sign*nums[k] + max(0, max_segment);
            max_all = max(max_all, max_segment);
        }
        
        return max_all;
    }
     
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int num: nums) sum+=num;
        
        if(n==1) return sum;
        
        int a = kadance(nums, 0, n-1, 1);
        int b = sum + kadance(nums, 1, n-1, -1);
        int c = sum + kadance(nums, 0, n-2, -1);
        
        return max(a,max(b,c));
    }
};