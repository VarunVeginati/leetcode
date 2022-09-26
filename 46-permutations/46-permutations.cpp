class Solution {
public:
    vector<vector<int>> res;
    int n;
    
    vector<int> getVec(vector<int> nums, int j) {
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++) {
            if(i!=j) res.push_back(nums[i]);
        }
        
        return res;
    }
    
    void bt(vector<int> nums, vector<int> vec) {
        if(vec.size()==n) {
            res.push_back(vec);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            vec.push_back(nums[i]);
            bt(getVec(nums,i), vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        bt(nums, {});
        return res;
    }
};