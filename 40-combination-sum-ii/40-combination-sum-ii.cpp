class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    
    void bt(int start, int rem, vector<int> vec) {
        if(rem ==0) {
            res.push_back(vec);
            return;
        }
        
        for(int i=start; i<nums.size(); ++i) {
            if(i>start && nums[i]==nums[i-1])
                continue;
            if(rem-nums[i]<0) break;
            
            vec.push_back(nums[i]);
            bt(i+1,rem-nums[i], vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        nums = candidates;
        vector<int> vec;
        
        bt(0, target, vec);
        
        return res;
    }
};