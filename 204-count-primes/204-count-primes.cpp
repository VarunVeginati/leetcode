class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        
        vector<bool> vec(n, true);
        
        for(int i=2; i<sqrt(n); i++) {
            if(vec[i]) {
                for(int j=i*i; j<n; j=j+i) {
                    vec[j] = false;
                }
            }
        }
        
        int cnt = 0;
        
        for(int i=2; i<n; i++) {
            if(vec[i]) cnt++;
        }
        
        return cnt;
    }
};