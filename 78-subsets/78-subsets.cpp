class Solution {
public:
    vector<vector<int>> res;
    vector<int> a;
    
    void bt(int start, vector<int> vec) {
        res.push_back(vec);
        
        for(int i=start; i<a.size(); i++) {
            vec.push_back(a[i]);
            bt(i+1, vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        a = nums;
        vector<int> vec;
        bt(0, vec);
        
        return res;
    }
};