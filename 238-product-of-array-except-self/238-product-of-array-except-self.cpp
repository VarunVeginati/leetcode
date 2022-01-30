class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int zeros = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) product *= nums[i];
            else zeros++;
        }
        
        vector<int> out;
        
        for(int i=0; i<nums.size(); i++) {
            if(zeros == 0) {
                out.push_back(product/nums[i]);
            } else if(zeros == 1) {
                if(nums[i] != 0) out.push_back(0);
                else out.push_back(product);
            } else {
                out.push_back(0);
            }
        }
        
        return out;
    }
};