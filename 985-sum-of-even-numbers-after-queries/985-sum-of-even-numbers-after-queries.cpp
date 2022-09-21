class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i]%2==0) evenSum += nums[i];
        
        vector<int> res;
        
        for(int i=0; i<queries.size(); i++) {
            if(nums[queries[i][1]]%2 != 0) {
                nums[queries[i][1]] = nums[queries[i][1]]+queries[i][0];
                if(nums[queries[i][1]] % 2 == 0) evenSum += nums[queries[i][1]];
                
                res.push_back(evenSum);
            } else {
                nums[queries[i][1]] = nums[queries[i][1]]+queries[i][0];
                if(nums[queries[i][1]] % 2 == 0) evenSum += queries[i][0];
                else evenSum -= (nums[queries[i][1]]-queries[i][0]);
                
                res.push_back(evenSum);
            }
        }
        
        return res;
    }
};