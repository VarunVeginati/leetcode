class Solution {
public:
    vector<vector<int>> res;
    
    void bt(vector<int> &candidates, int start, int target, vector<int> vec) {
        if(target==0) {
            res.push_back(vec);
            return;
        }
        if(target<0) return;
        
        for(int i=start; i<candidates.size(); i++) {
            vec.push_back(candidates[i]);
            bt(candidates, i, target-candidates[i], vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        bt(candidates, 0, target, {});
        
        return res;
    }
};