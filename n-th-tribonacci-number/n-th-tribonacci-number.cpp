class Solution {
public:
    map<int,int> m;
    
    int dp(int i) {
        if(i==0) return 0;
        if(i==1 || i==2) return 1;
        
        if(m[i] <= 0) {
            m[i] = dp(i-1)+dp(i-2)+dp(i-3);
        }
        
        return m[i];
    }
    
    int tribonacci(int n) {
        return dp(n);
    }
};