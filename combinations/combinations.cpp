class Solution {
public:
    vector<vector<int>> res;
    
    void back_track(int n, int k, vector<int> vec, int start) {
        if(vec.size() == k) {
            res.push_back(vec);
            return;
        } else if(start > n) return;
        
        for(int i=start; i<=n; i++) {
            vec.push_back(i);
            back_track(n, k, vec, i+1);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        back_track(n, k, vec, 1);
        return res;
    }
};