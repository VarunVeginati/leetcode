class Solution {
public:
    map<vector<int>, int> m;
    vector<vector<int>> res;
    
    vector<int> get_vec(vector<int> vec, int i) {
        vector<int> v;
        for(int j=0; j<vec.size(); j++)
            if(i!=j) v.push_back(vec[j]);
        
        return v;
    }
    
    void bt(vector<int> vec, vector<int> nums, int n) {
        if(vec.size()==n) {
            if(m[vec] <= 0) {
                m[vec]++;
                res.push_back(vec);
                return;
            }
        }
        
        for(int i=0; i<nums.size(); i++) {
            vec.push_back(nums[i]);
            bt(vec, get_vec(nums,i),n);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vec;
        bt(vec, nums, nums.size());
        
        return res;
    }
};