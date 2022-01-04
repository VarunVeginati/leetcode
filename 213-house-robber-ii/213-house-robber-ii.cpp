class Solution {
public:
    vector<int> vec;
    
    int dp(int start, int end) {
        int t1 = 0;
        int t2 = 0;
        
        for(int i=start; i<=end; i++) {
            int temp = t1;
            int current = vec[i];
            t1 = max(current+t2, t1);
            t2 = temp;
        }
        
        return t1;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vec = nums;
        int a = dp(0, nums.size()-2);
        int b = dp(1, nums.size()-1);
        
        return max(a,b);
    }
};