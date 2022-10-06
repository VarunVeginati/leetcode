class Solution {
    int[] memo;
    
    int dp(int i, String s) {
        if(i==s.length()) return 1;
        if(s.charAt(i)=='0') return 0;
        if(i==s.length()-1) return 1;
    
        if(memo[i] != -1) return memo[i];
        
        int ans = dp(i+1, s);
        if(Integer.parseInt(s.substring(i,i+2)) <= 26)
            ans += dp(i+2, s);
        
        memo[i] = ans;
        
        return ans;
    }
    
    public int numDecodings(String s) {
        memo = new int[s.length()+1];
        
        for(int i=0; i<memo.length; i++)
            memo[i] = -1;
        
        return dp(0, s);
    }
}