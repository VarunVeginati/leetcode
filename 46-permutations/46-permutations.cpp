class Solution {
public:
    vector<vector<int>> res;
    int n;
    
    void bt(vector<int> &nums, vector<int> vec, set<int> s) {
        if(vec.size()==n) {
            res.push_back(vec);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(s.find(i) != s.end()) continue;
            vec.push_back(nums[i]);
            s.insert(i);
            bt(nums, vec, s);
            s.erase(i);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        set<int> s;
        bt(nums, {}, s);
        return res;
    }
};