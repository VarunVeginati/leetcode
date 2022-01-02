class Solution {
public:
    vector<vector<int>> res;
    int n;
    int cnt = 0;
    int total_cnt;
    
    int fact(int n) {
        if(n<=1) return 1;
        return n*fact(n-1);
    }
    
    vector<int> get_vec(vector<int> main ,int i) {
        vector<int> vec;
        for(int j=0; j<main.size(); j++)
            if(i!=j) vec.push_back(main[j]);
        return vec;
    }
    
    void back_track(vector<int> vec, vector<int> main) {
        if(cnt == total_cnt) return;
        if(vec.size() == n) {
            res.push_back(vec);
            cnt++;
            return;
        }
        
        for(int i=0; i<main.size(); i++) {
            vec.push_back(main[i]);
            back_track(vec, get_vec(main, i));
            vec.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        total_cnt = fact(nums.size());
        vector<int> vec;
        back_track(vec, nums);
        
        return res;
    }
};