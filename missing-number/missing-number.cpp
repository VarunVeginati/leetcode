class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> vec(nums.size()+1, 0);
        
        for(int i=0; i<nums.size(); i++) {
            vec[nums[i]] = 1;
        }
        
        for(int i=0; i<vec.size(); i++) {
            if(vec[i]!=1) return i;
        }
        
        return -1;
    }
};