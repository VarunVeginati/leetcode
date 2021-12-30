class Solution {
public:
    vector<vector<int>> res;
    int n;
    int k;
    vector<int> vec;
    
    
    void back_track(int start) {
        if(vec.size() == k) {
            res.push_back(vec);
            return;
        } else if(start > n) return;
        
        for(int i=start; i<=n; i++) {
            vec.push_back(i);
            back_track(i+1);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combine(int p, int q) {
        n = p;
        k = q;
        back_track(1);
        return res;
    }
};