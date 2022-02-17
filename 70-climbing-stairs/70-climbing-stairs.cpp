class Solution {
public:
    vector<int> vec;
    
    int dp(int i, int n) {
        if(i>n) return 0;
        if(i==n-1 || i==n) return 1;
        
        if(vec[i] != -1) return vec[i];
        
        vec[i] = dp(i+1,n)+dp(i+2,n);
        
        return vec[i];
    }
    
    int climbStairs(int n) {
        vec = vector<int> (n+1, -1);
        
        return dp(0,n);
    }
};