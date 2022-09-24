class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int n = nums.size();
        vector<vector<int>> res;
        
        while(i<n){
            int j = i+1;
            
            while(j<n) {
                int k= j+1;
                int l = n-1;
                
                while(k<l) {
                    long sum = (long)nums[i]+(long)nums[j]+(long)nums[k]+(long)nums[l];
                    
                    if(sum==target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k = upper_bound(nums.begin()+k, nums.end(), nums[k]) - nums.begin();
                        l = lower_bound(nums.begin(), nums.end(), nums[l]) - nums.begin();
                    } else if(sum>target) {
                        l--;
                    } else {
                        k++;
                    }
                }
                
                j = upper_bound(nums.begin()+j, nums.end(), nums[j]) - nums.begin();
            }
            i = upper_bound(nums.begin()+i, nums.end(), nums[i]) - nums.begin();
        }
        
        return res;
    }
};