class Solution {
public:
    vector<pair<int,int> > vec;
    map<int,int> memo;
    
    int dp(int i) {
        if(i==0) return (vec[0].first*vec[0].second);
        if(i==1) {
            if(vec[0].first+1 == vec[1].first)
                return max(vec[0].first*vec[0].second, vec[1].first*vec[1].second);
            else
                return vec[0].first*vec[0].second+vec[1].first*vec[1].second;
        }
        
        if(memo.find(i) == memo.end()) {
            if(vec[i].first-1 == vec[i-1].first)
                memo[i] = max(vec[i].first*vec[i].second + dp(i-2), dp(i-1));
            else
                memo[i] = vec[i].first*vec[i].second+dp(i-1);
        }
        
        return memo[i];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;
        
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        
        for(auto it: m) {
            vec.push_back(make_pair(it.first, it.second));
        }
        
        sort(vec.begin(), vec.end());
        
        return dp(vec.size()-1);
    }
};