class Solution {
public:
    vector<int> vec;
    vector<int> val;
    
    int dp(int i) {
        if(i==val.size()-2) {
            return val[i]+val[i+1]-1;
        }
        
        if(vec[i] == 0) {
            int a = val[i]+val[i+1]-1;
            int b = val[i]+dp(i+1)-val[i+1]-1;
            vec[i] = max(a,b);
        }
        
        return vec[i];
    }
    
    int maxScoreSightseeingPair(vector<int>& values) {
        vec = vector<int>(values.size(), 0);
        val = values;
        
        int mx = INT_MIN;
        for(int i=0; i<values.size()-1; i++) {
            mx = max(mx, dp(i));
        }
        
        return mx;
    }
};