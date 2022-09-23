class Solution {
public:
    int getBinaryLen(int n) {
        int s = 0;
        
        while(n>0) {
            s++;
            n=n/2;
        }
        
        return s;
    }
    
    long getPow(int j) {
        int mod = 1000000007;
        long k = 1;
        int m = 33;
        
        while(j>0) {
            if(j>m) k = (k%mod*(long)pow(2,m)%mod)%mod;
            else k = (k%mod*(long)pow(2,j)%mod)%mod;
            
            j = j-m;
        }
        
        return k;
    }
    
    int concatenatedBinary(int n) {
        string s = "";
        long j =1;
        long ans = 0;
        int mod = 1000000007;
        
        for(int i=n; i>=1; i--) {
            if(i!=n) j = ((j%mod)*((long)pow(2,getBinaryLen(i+1))%mod))%mod;
            ans += (i*j);
            ans = ans%mod;
        }
        
        return ans;
    }
};