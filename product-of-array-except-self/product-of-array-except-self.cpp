class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        int n = nums.size();
        vector<int> right(n+1);
        
        left.push_back(1);
        right[n] = 1;
        
        for(int i=0; i<n; i++) {
            left.push_back(nums[i]*left.back());
            right[n-i-1] = nums[n-i-1]*right[n-i];
        }
        
        vector<int> res;
        
        for(int i=1; i<=n; i++) {
            res.push_back(left[i-1]*right[i]);
        }
        
        return res;
    }
};