class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        long long curr = 1;
        int i=0;
        
        while(curr<=n) {
            curr = pow(3,i);
            if(curr==n) return true;
            i++;
        }
        
        return false;
    }
};