class Solution {
    int[][] mem;
    
    int dp(int n, int target, int k) {
        if(n==0 && target==0) return 1;
        if(n<=0 || target<0) return 0;
        if(target > (int)Math.pow(k,n)) return 0;
        
        if(mem[n][target] != -1) return mem[n][target];
        
        int sum = 0;
        
        for(int i=1; i<=k; i++) {
            sum = (sum+dp(n-1,target-i, k))%1000000007;
        }
        
        mem[n][target] = sum;
        return sum;
    }
    
    public int numRollsToTarget(int n, int k, int target) {
        mem = new int[n+1][target+1];
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=target; j++) {
                mem[i][j] = -1;
            }
        }
        
        return dp(n, target, k);
    }
}