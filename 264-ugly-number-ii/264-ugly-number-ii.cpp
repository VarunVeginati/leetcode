class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vec(n);
        vec[0]=1;
        
        int two=0, three=0, five=0;
        
        for(int i=1;i<n; i++) {
            vec[i] = min(vec[two]*2, min(vec[three]*3, vec[five]*5));
            
            if(vec[i]==vec[two]*2) two++;
            if(vec[i]==vec[three]*3) three++;
            if(vec[i]==vec[five]*5) five++;
        }
        
        return vec[n-1];
    }
};