class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = -1;
        
        int sum = 0;
        int max_sum = 0;
        
        map<int,int> m;
        
        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) {
                sum += nums[i];
            } else {
                while(left<m[nums[i]]) {
                    left++;
                    sum -= nums[left];
                }
                sum += nums[i];
            }
            
            m[nums[i]] = i;
            max_sum = max(max_sum, sum);
        }
        
        return max_sum;
    }
};