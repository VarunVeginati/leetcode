class Solution {
public:
    vector<int> calculate1s(vector<int> &nums) {
        vector<int> vec;
        
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==1) {
                vec.push_back(-1);
                cnt++;
            } else {
                vec.push_back(cnt);
                cnt = 0;
            }
        }
        
        return vec;
    }
    
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> left_array = calculate1s(nums);
        reverse(nums.begin(), nums.end());
        vector<int> right_array = calculate1s(nums);
        reverse(right_array.begin(), right_array.end());
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=-1) {
                ans = max(ans, left_array[i]+right_array[i]+1);
            }
        }
        
        if(ans==0) {
            nums.push_back(0);
            return findMaxConsecutiveOnes(nums)-1;
        }
        
        return ans;
    }
};